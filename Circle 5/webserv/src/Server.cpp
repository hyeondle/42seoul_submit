#include "Server.hpp"
#include "Utils.hpp"
#include <stdexcept>
#include <sys/stat.h>


Server::Server(std::ifstream& config_file) {
	parse(config_file);
	initMimeTypes();
	clientMaxBodySize = SIZE_T_MAX;
	init_code2status();
}

Server::~Server() {
    // 구현 내용
}


void Server::configure(const std::string& configPath) {
	//  파일 열기
	std::ifstream conf(configPath);
	if (!conf.is_open()) throw(std::runtime_error("Server::configure : cannot open config file"));

	parse(conf);
	conf.close();
}

void Server::parse(std::ifstream& file) {
	// ToDo: server 중괄호 유효성 검사
	std::string line;
	std::streampos position = file.tellg();
	while (std::getline(file, line)) {
		// FixMe: 대충 "}"로 시작하는지만 확인하고 탈출. 문제가 발생할 여지있음
		trim(line);
		if (line[0] == '}') break;

		std::vector<std::string> tokens = string_to_tokens(line);
		if (line.empty() || line[0] == '#' || tokens.size() == 0){
			position = file.tellg();
			continue;
		}

		if (tokens[0] == "location")
			parse_location(file, position);
		else if (tokens[0] == "cgi") parse_cgi(file, position);
		else parse_server(tokens);
		position = file.tellg();
	}
	printALL();
}

void Server::parse_server(std::vector<std::string>& tokens) {
	//{std::cout << "token = " << tokens[0] << std::endl;}

	if (tokens[0] == "listen") {
		this->port = std::stoi(tokens[1]);
	} else if (tokens[0] == "server_name") {
		this->serverName.insert(this->serverName.end(), tokens.begin() + 1, tokens.end());
	} else if (tokens[0] == "error_page") {
		this->errorPages[std::stoi(tokens[1])] = tokens[2];
	} else if (tokens[0] == "client_max_body_size") {
		this->clientMaxBodySize = convert_to_bytes(tokens[1]);
	} else if (tokens[0] == "cgi_extension") {
		this->cgiPerExtension[tokens[1]] = tokens[2];
	}
}

void Server::parse_location(std::ifstream& file, std::streampos& position) {
	// ToDo: location 중괄호 유효성 검사
	file.seekg(position);
	std::string line;
	std::getline(file, line);
	std::vector<std::string> location_tokens = string_to_tokens(line);
	//tri.insert(location_tokens[1]);

	while (std::getline(file, line)) {
		//{std::cout << "line = " << line << std::endl;}
		trim(line);
		std::vector<std::string> tokens = string_to_tokens(line);
		if (line.empty() || line[0] == '#' || tokens.size() == 0) continue;
		if (tokens[0] == "}") break;

		if (tokens[0] == "allow") {
			this->allowedMethodsPerLocation[location_tokens[1]].insert(tokens[1]);
			tri_allowedMethodsPerLocation.insert(location_tokens[1]);
		} else if (tokens[0] == "deny") {
			this->allowedMethodsPerLocation[location_tokens[1]].erase(tokens[1]);
			tri_allowedMethodsPerLocation.insert(location_tokens[1]);
		} else if (tokens[0] == "return") {
			// FixMe: 현재 멤버 변수로는 status code 지정 불가
			this->redirections[location_tokens[1]] = tokens[2];
			tri_redirections.insert(location_tokens[1]);
		} else if (tokens[0] == "autoindex") {
			this->directoryListing[location_tokens[1]] = (tokens[1] == "on");
			tri_directoryListing.insert(location_tokens[1]);
		} else if (tokens[0] == "index") {
			this->defaultFiles[location_tokens[1]] = tokens[1];
			tri_defaultFiles.insert(location_tokens[1]);
		} else if (tokens[0] == "upload_path") {
			// ToDo: client_body_in_file_only...등등 기타 속성 어떻게 처리할지?
			this->uploadPaths[location_tokens[1]] = tokens[1];
			tri_uploadPaths.insert(location_tokens[1]);
		} else if (tokens[0] == "cgi_pass") {
			this->cgiPerLocation[location_tokens[1]] = tokens[1];
			tri_cgiPerLocation.insert(location_tokens[1]);
		} else if (tokens[0] == "alias") {
			this->aliases[location_tokens[1]] = tokens[1];
			tri_aliases.insert(location_tokens[1]);
		} else if (tokens[0] == "client_max_body_size") {
			this->clientMaxBodySizes[location_tokens[1]] = (size_t)atol(tokens[1].c_str());
			tri_maxsize.insert(location_tokens[1]);
		}
	}
}

void Server::parse_cgi(std::ifstream& file, std::streampos& position) {
	// ToDo: cgi 중괄호 유효성 검사
	file.seekg(position);
	std::string line;
	std::getline(file, line);
	std::vector<std::string> location_tokens = string_to_tokens(line);

	while (std::getline(file, line)) {
		trim(line);
		std::vector<std::string> tokens = string_to_tokens(line);
		if (line.empty() || line[0] == '#' || tokens.size() == 0) continue;
		if (tokens[0] == "}") break;

		if (tokens[0] == "script") {
			this->cgiPerExtension[location_tokens[1]] = tokens[1];
		}
	}
}

/*
void Server::serveRequest() {
    // 구현 내용
}
*/

void Server::printALL() {
	std::cout << std::endl;
	std::cout << "↓↓↓↓↓↓↓Server Parsed↓↓↓↓↓↓↓↓↓" << std::endl;

	std::cout << "port : " << this->port << std::endl;
	std::cout << "serverName : ";
	for (std::vector<std::string>::iterator it = this->serverName.begin(); it != this->serverName.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
	std::cout << "errorPages : ";
	for (std::map<int, std::string>::iterator it = this->errorPages.begin(); it != this->errorPages.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = " << it->second;
	}
	std::cout << std::endl;
	std::cout << "clientMaxBodySize : " << this->clientMaxBodySize << std::endl;
	std::cout << "allowedMethodsPerLocation : ";
	for (std::map<std::string, std::set<std::string> >::iterator it = this->allowedMethodsPerLocation.begin(); it != this->allowedMethodsPerLocation.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = ";
		for (std::set<std::string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			std::cout << *it2 << ", ";
		}
	}
	std::cout << std::endl;
	std::cout << "redirections : ";
	for (std::map<std::string, std::string>::iterator it = this->redirections.begin(); it != this->redirections.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = " << it->second;
	}
	std::cout << std::endl;
	std::cout << "directoryListing : ";
	for (std::map<std::string, bool>::iterator it = this->directoryListing.begin(); it != this->directoryListing.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = " << (it->second ? "on" : "off");
	}
	std::cout << std::endl;
	std::cout << "defaultFiles : ";
	for (std::map<std::string, std::string>::iterator it = this->defaultFiles.begin(); it != this->defaultFiles.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = " << it->second;
	}
	std::cout << std::endl;
	std::cout << "uploadPaths : ";
	for (std::map<std::string, std::string>::iterator it = this->uploadPaths.begin(); it != this->uploadPaths.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = " << it->second;
	}
	std::cout << std::endl;
	std::cout << "cgiPerLocation : ";
	for (std::map<std::string, std::string>::iterator it = this->cgiPerLocation.begin(); it != this->cgiPerLocation.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = " << it->second;
	}
	std::cout << std::endl;
	std::cout << "cgiPerExtension : ";
	for (std::map<std::string, std::string>::iterator it = this->cgiPerExtension.begin(); it != this->cgiPerExtension.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = " << it->second;
	}
	std::cout << std::endl;
	std::cout << "aliases : ";
	for (std::map<std::string, std::string>::iterator it = this->aliases.begin(); it != this->aliases.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = " << it->second;
	}
	std::cout << std::endl;
	std::cout << "clientMaxBodySizes : ";
	for (std::map<std::string, size_t>::iterator it = this->clientMaxBodySizes.begin(); it != this->clientMaxBodySizes.end(); it++) {
		std::cout << std::endl;
		std::cout << " - " << it->first << " = " << it->second;
	}
	std::cout << std::endl;
	std::cout << "↑↑↑↑↑↑↑↑Server Parsed↑↑↑↑↑↑↑↑↑↑" << std::endl;
	std::cout << std::endl;
}

std::vector<std::string> Server::getServerName() const {
    return this->serverName;
}

int Server::getPort() const {
	return this->port;
    // 구현 내용
}




static bool isdirectory(const std::string& path) {
    struct stat statbuf;
    if (stat(path.c_str(), &statbuf) != 0)
        return false;
    return S_ISDIR(statbuf.st_mode);
}

std::string Server::uri2path(std::string uri)
{	
	std::string path;
	
	std::string matchedLocation = tri_aliases.findLongestMatchingPath(uri);
	size_t matchedLength = matchedLocation.length();

	{std::cout << "in uri2path" << std::endl;}

	{std::cout << "in uri2path : uri = "<< uri << std::endl;}
	{std::cout << "in uri2path : matched location = "<< matchedLocation << std::endl;}

	tri_aliases.printAllPaths();



	// // 만약 location 주소와 정확히 매치되면,
	// if (matchedLength == uri.length()){
	// 	{std::cout << "in uri2path : exact match" << std::endl;}
		
	// 	// (디렉터리 리스팅은 신경쓸 필요 없고) 기본파일 확인
	// 	std::map<std::string, std::string>::iterator dit = defaultFiles.find(uri);
	// 	if (dit != defaultFiles.end()) {
	// 		path = dit->second;
	// 		//{std::cout << "설마 여기?" << std::endl;}

	// 		return path;
	// 	}
	// }

	//alias 적용
	std::map<std::string, std::string>::iterator it = aliases.find(matchedLocation);
	if (it != aliases.end()) {
		{std::cout << "in uri2path : matched, matched length ="<< matchedLength << std::endl;}
		path = it->second;
		{std::cout << "uri2path :  it->second ==== " << it->second << std::endl;}
		path += uri.substr(matchedLength);
		//path.append(uri.substr(matchedLength));
	} else {
		{std::cout << "in uri2path : nothind matched" << std::endl;}
		path = uri;
	}

	{std::cout << "in uri2path : path in process = "<<path << std::endl;}

	if (isdirectory(path)) 
	{
		{std::cout << "in uri2path : folder to index" << std::endl;}
		
		// (디렉터리 리스팅은 신경쓸 필요 없고) 기본파일 확인
		std::map<std::string, std::string>::iterator dit = defaultFiles.find(matchedLocation);
		if (dit != defaultFiles.end()) {
			path = path + "/" + dit->second;
			{std::cout << "in uri2path : index matched" << std::endl;}
		}
		else {
			{std::cout << "in uri2path : index not matched" << std::endl;}

		}
		
	}
	{std::cout << "in uri2path : end" << std::endl;}

	return path;
}

std::string Server::uri2CGIPath(std::string uri)
{
	// {std::cout << "in uri2CGIPath : start" << std::endl;}

    std::string path;
    // trie를 이용해서
    std::string matchedLocation_loc = tri_cgiPerLocation.findLongestMatchingPath(uri);
    //std::string matchedLocation_ext = tri_cgiPerExtension.findLongestMatchingPath(uri);


    // Check if there's a specific CGI path for this location
    std::map<std::string, std::string>::iterator it = cgiPerLocation.find(matchedLocation_loc);
    if (it != cgiPerLocation.end()) {
		// {std::cout << "in uri2CGIPath : matched with location : " << it->first << std::endl;}
        path = it->second;
    } 
    else {
		// If not found, check if there's a CGI path for the file extension
		std::string extension = extractExtension(uri); // Function to extract file extension from URI
		it = cgiPerExtension.find(extension);
		if (it != cgiPerExtension.end()) {
			// {std::cout << "in uri2CGIPath : matched with extention : "<< extension << it->first << std::endl;}
			path = it->second;}
		else {path = "-isnotCGI";}
	}
	// {std::cout << "in uri2CGIPath : end , CGIpath ===== " << path << std::endl;}
    return path;
}

bool Server::uricanMethod(std::string uri, std::string method)
{
    // 서버 설정의 경로 중 가장 긴 매칭 탐색
    std::string matchedLocation = tri_allowedMethodsPerLocation.findLongestMatchingPath(uri);

    // Search for the matched location in the map
	// std::cout << "URICANMETHOD" << std::endl;
    std::map<std::string, std::set<std::string> >::iterator it = allowedMethodsPerLocation.find(matchedLocation);
    if (it != allowedMethodsPerLocation.end()) {
        // Check if the method is in the set of allowed methods for this location
        std::set<std::string>& allowedMethods = it->second;
        if (allowedMethods.find(method) != allowedMethods.end()) {
            return true; // Method is allowed
        }
    }
	// std::cout << "RETURN FALSE" << std::endl;
    return false; // Method is not allowed or location is not configured
}

std::string Server::uri2uploadLocation(std::string uri)                 // uri 를 받아서 업로드 할 경로를 리턴
{	
	std::string path;
	
	std::string matchedLocation = tri_uploadPaths .findLongestMatchingPath(uri);
	size_t matchedLength = matchedLocation.length();

	//tri_uploadPaths.printAllPaths();

	//alias 처럼 upload location 적용
	std::map<std::string, std::string>::iterator it = uploadPaths.find(matchedLocation);
	if (it != uploadPaths.end()) {
		path = it->second;
		path += uri.substr(matchedLength);
	} else {
		{std::cout << "in uri2Uploadpath : uploadpath = "<< path << std::endl;}
		path = "-cannotUpload";
	}
	{std::cout << "in uri2Uploadpath : uploadpath = "<< path << std::endl;}
	return path;
}


//std::pair<int, std::string> uri2redirection(std::string uri);
std::string Server::uri2redirection(std::string uri){

	std::string path;
	
	std::string matchedLocation = tri_redirections.findLongestMatchingPath(uri);
	size_t matchedLength = matchedLocation.length();
	//tri_aliases.printAllPaths()

	//alias 적용ㄹ
	std::map<std::string, std::string>::iterator it = redirections.find(matchedLocation);
	if (it != redirections.end()) {
		//{std::cout << "in uri2redirection : matched" << std::endl;}
		path = it->second;
		//{std::cout << "uri2redirection :  it->second ==== " << it->second << std::endl;}
		path += uri.substr(matchedLength);
	} else {
		//{std::cout << "in uri2redirection : nothind matched" << std::endl;}
		path = "-isnotRedirection";
	}
	
	return path;
}

bool Server::uri2directoryListing(std::string uri) {
	
	std::string matchedLocation = tri_directoryListing.findLongestMatchingPath(uri);

	// longest 매칭 디렉터리 검색
    std::map<std::string, bool >::iterator it = directoryListing.find(matchedLocation);
    if (it != directoryListing.end()) {
        // 디렉터리별 저장되어 있는 값 적용
		return it->second;
    }
	return false;
}

size_t Server::uri2maxsize(std::string uri)
{
	std::string matchedLocation = tri_maxsize.findLongestMatchingPath(uri);

	// longest 매칭 디렉터리 검색
    std::map<std::string, size_t >::iterator it = clientMaxBodySizes.find(matchedLocation);
    if (it != clientMaxBodySizes.end()) {
        // 디렉터리별 저장되어 있는 값 적용
		return it->second;
    }
	return this->clientMaxBodySize;
}


// Helper function to extract file extension from URI
std::string Server::extractExtension(const std::string& uri) {
    size_t dotPos = uri.find_last_of('.');
    if(dotPos != std::string::npos) {
        return uri.substr(dotPos + 1);
    }
    return "";
}



void Server::initMimeTypes()
{
    mimetypes["txt"] = "text/plain";
    mimetypes["html"] = "text/html";
    mimetypes["css"] = "text/css";
    mimetypes["js"] = "application/javascript";
    mimetypes["json"] = "application/json";
    mimetypes["png"] = "image/png";
    mimetypes["jpg"] = "image/jpeg";
    mimetypes["jpeg"] = "image/jpeg";
    mimetypes["gif"] = "image/gif";
    mimetypes["svg"] = "image/svg+xml";
    mimetypes["ico"] = "image/x-icon";
    mimetypes["pdf"] = "application/pdf";
    mimetypes["mp3"] = "audio/mpeg";
    mimetypes["wav"] = "audio/wav";
    mimetypes["mp4"] = "video/mp4";
    mimetypes["woff"] = "font/woff";
    mimetypes["woff2"] = "font/woff2";
    mimetypes["ttf"] = "font/ttf";
    mimetypes["otf"] = "font/otf";
    mimetypes["eot"] = "application/vnd.ms-fontobject";
    mimetypes["sfnt"] = "application/font-sfnt";
    mimetypes["xml"] = "application/xml";
    mimetypes["swf"] = "application/x-shockwave-flash";
    mimetypes["flv"] = "video/x-flv";
    mimetypes["psd"] = "image/vnd.adobe.photoshop";
    mimetypes["ai"] = "application/postscript";
    mimetypes["eps"] = "application/postscript";
    mimetypes["ps"] = "application/postscript";
    mimetypes["doc"] = "application/msword";
    mimetypes["docx"] = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
    mimetypes["xls"] = "application/vnd.ms-excel";
    mimetypes["xlsx"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
    mimetypes["ppt"] = "application/vnd.ms-powerpoint";
    mimetypes["pptx"] = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
    mimetypes["odt"] = "application/vnd.oasis.opendocument.text";
    mimetypes["ods"] = "application/vnd.oasis.opendocument.spreadsheet";
    mimetypes["odp"] = "application/vnd.oasis.opendocument.presentation";
    mimetypes["odg"] = "application/vnd.oasis.opendocument.graphics";
    mimetypes["odc"] = "application/vnd.oasis.opendocument.chart";
    mimetypes["odb"] = "application/vnd.oasis.opendocument.database";
    mimetypes["odf"] = "application/vnd.oasis.opendocument.formula";
    mimetypes["odm"] = "application/vnd.oasis.opendocument.text-master";
    mimetypes["ott"] = "application/vnd.oasis.opendocument.text-template";
    mimetypes["ots"] = "application/vnd.oasis.opendocument.spreadsheet-template";
    mimetypes["otp"] = "application/vnd.oasis.opendocument.presentation-template";
    mimetypes["otg"] = "application/vnd.oasis.opendocument.graphics-template";
    mimetypes["otc"] = "application/vnd.oasis.opendocument.chart-template";
    mimetypes["otf"] = "application/vnd.oasis.opendocument.formula-template";
    mimetypes["oth"] = "application/vnd.oasis.opendocument.text-web";
    mimetypes["rtf"] = "application/rtf";
    mimetypes["jar"] = "application/java-archive";
    mimetypes["war"] = "application/java-archive";
    mimetypes["ear"] = "application/java-archive";
    mimetypes["hqx"] = "application/mac-binhex40";
}


std::string Server::getMimeType(const std::string& filePath) {

	std::map<std::string, std::string>::iterator it = mimetypes.find(extractExtension(filePath));
	if (it != mimetypes.end()) {
		return it->second;
	}
    return "application/octet-stream";
}


size_t Server::getclientBodysize(){
	return this->clientMaxBodySize;
}


std::string Server::errorPagePath(int num)
{
	std::map<int, std::string>::iterator it = this->errorPages.find(num);

	if (it != this->errorPages.end()) {return it->second;}
	return "-useDefualt";
}


std::string Server::defaultErrorPage(int num) {
    std::stringstream ss;
    ss << "<html>\r\n"
       << "<head><title> " << num << " " << this->code2status(num) << " </title></head>\r\n"
       << "<body>\r\n"
       << "<center><h1> " << num << " " << this->code2status(num) << " </h1></center>\r\n"
       << "<hr><center>webserv</center></body>\r\n"
       << "</html>";

    return ss.str();
}


void Server::init_code2status()
{
    this->codeAndStatus[200] = "OK";
    this->codeAndStatus[201] = "Created";
    this->codeAndStatus[202] = "Accepted";
    this->codeAndStatus[204] = "No Content";
    this->codeAndStatus[301] = "Moved Permanently";
    this->codeAndStatus[302] = "Found";
    this->codeAndStatus[303] = "See Other";
    this->codeAndStatus[304] = "Not Modified";
    this->codeAndStatus[307] = "Temporary Redirect";
    this->codeAndStatus[308] = "Permanent Redirect";
    this->codeAndStatus[400] = "Bad Request";
    this->codeAndStatus[401] = "Unauthorized";
    this->codeAndStatus[403] = "Forbidden";
    this->codeAndStatus[404] = "Not Found";
    this->codeAndStatus[405] = "Method Not Allowed";
    this->codeAndStatus[406] = "Not Acceptable";
    this->codeAndStatus[408] = "Request Timeout";
    this->codeAndStatus[409] = "Conflict";
    this->codeAndStatus[410] = "Gone";
    this->codeAndStatus[413] = "Payload Too Large";
    this->codeAndStatus[414] = "URI Too Long";
    this->codeAndStatus[415] = "Unsupported Media Type";
    this->codeAndStatus[418] = "I'm a teapot";
    this->codeAndStatus[429] = "Too Many Requests";
    this->codeAndStatus[451] = "Unavailable For Legal Reasons";
    this->codeAndStatus[500] = "Internal Server Error";
    this->codeAndStatus[501] = "Not Implemented";
    this->codeAndStatus[502] = "Bad Gateway";
    this->codeAndStatus[503] = "Service Unavailable";
    this->codeAndStatus[504] = "Gateway Timeout";
    this->codeAndStatus[505] = "HTTP Version Not Supported";
}

std::string Server::code2status(int code) {
	std::map<int, std::string>::iterator it = codeAndStatus.find(code);
	if (it != codeAndStatus.end()) {
		return it->second;
	}
	return "Unknown";
}