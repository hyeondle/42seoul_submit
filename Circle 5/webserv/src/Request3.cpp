#include "Request3.hpp"
#include "IOServer.hpp"
#include "Utils.hpp"
#include "Server.hpp"
#include "DirectoryListing.hpp"
#include <string>
#include <unistd.h>
#include <signal.h>
//#include <iomanip>
# define FL(i, n) for(size_t i=0; i < n; i++)

Request::Request(int client_socket, Connection* connection) : client_socket(client_socket), connection(connection), cgiState(IDLE) {
	isSlashEnd = false;
}


void Request::handleMessage(uintptr_t uintptr_request, std::string message) {
    std::cout << "Request : handleMessage called : " << message << std::endl;
	(void)uintptr_request;
	if (message == "re subscribe write")
	{
		//IOServer::getInstance().subscribe((int)uintptr_request, "write", this);
	}
	
}

std::string Request::getErrorStatus(int code)
{
	if (code == 413)
		return "413 Request Entity Too Large";
	return "500 Not Implemented";
}

void Request::processRequest() {
	std::cout << " Request " << this <<" : process request called" << std::endl;
	// parseRequest();
	std::cout << "ERROR_CODE : " << error_code << std::endl;
	if (error_code != 0)
	{
		std::cout << "Error Occured" << std::endl;
		// std::string default_error_page = server->errorPagePath(error_code);
		// std::vector<char> data;
		// readFileContents(default_error_page, data);
		// std::string error_status = getErrorStatus(error_code);
		// // sendHttpResponseGet(client_socket, data, error_status);
		// sendHttpResponseGet(data, error_status);
		sendResponseError(error_code);
		return ;
	}

	std::string redirection_uri;
	if ( (redirection_uri = server->uri2redirection(uri)) != "-isnotRedirection")
	{
		sendResponseRedirect(redirection_uri);
		return;
	}

	if (method == "GET" && server->uricanMethod(uri, "GET")) {
		std::cout << "Request" << this <<".processRequest : Get called" << std::endl;
		handleGet();
	// } else if (method == "POST"  && server->uricanMethod(uri, "POST")) {
	} else if (method == "POST" && server->uricanMethod(uri, "POST")) {
		std::cout<< "Request" << this <<".processRequest : Post called" << std::endl;
		handlePost();
	// } else if (method == "DELETE"  && server->uricanMethod(uri, "DELETE")) {
	} else if (method == "DELETE" && server->uricanMethod(uri, "DELETE")) {
		std::cout<< "Request" << this <<".processRequest : Delete called" << std::endl;
		handleDelete();
	} else {
		std::cout<< "Request" << this <<".processRequest : Method Not Allowed" << std::endl;
		// sendResponse("405 Method Not Allowed", "Method not implemented.");
		sendResponseError(405);
	}
	std::cout << " Request " << this <<" : processRequest end" << std::endl;
	// IOServer::getInstance().deliverEvent(uintptr_t(this), "shutdown_connection", connection);
}

void Request::makeenv(const std::string &data) {
	// char *cwd = getcwd(NULL, 0);

	this->envmap["REQUEST_METHOD"] = method;
	this->envmap["QUERY_STRING"] = this->queryString;
	this->envmap["SERVER_PORT"] = std::to_string(server->getPort());
	this->envmap["SERVER_NAME"] = server->getServerName().front();
	this->envmap["SERVER_SOFTWARE"] = "mywebseeeerv";
	this->envmap["SERVER_PROTOCOL"] = "HTTP/1.1";
	this->envmap["CONTENT_TYPE"] = headers["Content-Type"];
	this->envmap["CONTENT_LENGTH"] = std::to_string(data.size());
	this->envmap["GATEWAY_INTERFACE"] = "CGI/1.1";
	this->envmap["REDIRECT_STATUS"] = "200";
	this->envmap["PATH_INFO"] = server->uri2CGIPath(uri);
	this->envmap["PATH_TRANSLATED"] = server->uri2CGIPath(uri);
	this->envmap["SCRIPT_FILENAME"] = server->uri2CGIPath(uri);
	this->envmap["REQUEST_URI"] = server->uri2CGIPath(uri);
	this->envmap["SCRIPT_NAME"] = server->uri2CGIPath(uri);
	this->envmap["AUTH_TYPE"] = "Basic";
	this->envmap["REMOTE_USER"] = "Basic";
	this->envmap["REMOTE_IDENT"] = "Basic";

	std::string clientInfo = "CLINET_INFO=" + connection->client_host();
	size_t colonPos = clientInfo.find(':');
	this->envmap["REMOTE_HOST"] = clientInfo.substr(0, colonPos);
	this->envmap["REMOTE_ADDR"] = clientInfo.substr(colonPos + 1);

	for (std::map<std::string, std::string>::iterator it = headers.begin(); it != headers.end(); it++) {
		std::string name = it->first;
		std::transform(name.begin(), name.end(), name.begin(), ::toupper);
		std::string key = "HTTP_" + name;
		// std::replace(key.begin(), key.end(), '-', '_');
		envmap[key] = it->second;
	}

	this->envp = (char **)calloc(sizeof(char *), envmap.size() + 1);
	std::map<std::string, std::string>::iterator it = envmap.begin();
	for (int i = 0; it != envmap.end(); it++, i++) {
		std::string env = it->first + "=" + it->second;
		this->envp[i] = strdup(env.c_str());
	}
	this->envp[envmap.size()] = NULL;
}

void Request::executeCgiScript(const std::string& scriptPath, const std::string& postData) {
	// 파이프 생성
	if (pipe(pipe_stdin) != 0 || pipe(pipe_stdout) != 0) {
		std::cerr << "Failed to create pipes" << std::endl;
		return;
	}

	envp = NULL;
	// CGI 스크립트를 실행할 자식 프로세스 생성
	pid_t pid = fork();
	if (pid == 0) {
		// 자식 프로세스
		std::vector<char*> args;
		args.push_back(const_cast<char*>(scriptPath.c_str()));
		args.push_back(const_cast<char*>(file_path.c_str()));
		args.push_back(NULL);
		char** argv = &args[0];
		makeenv(postData);

		dup2(pipe_stdin[0], STDIN_FILENO);
		dup2(pipe_stdout[1], STDOUT_FILENO);
		close(pipe_stdin[1]);
		close(pipe_stdout[0]);

		execve(scriptPath.c_str(), argv, envp);
		free(envp);
		//std::cout << "failed to run" << std::endl;
		exit(1); // execve 실패
	} else if (pid > 0) {
		// 부모 프로세스
		stdinfd = pipe_stdin[1];
		stdoutfd = pipe_stdout[0];
		close(pipe_stdin[0]);
		close(pipe_stdout[1]);
		fcntl(pipe_stdin[1], F_SETFL, O_NONBLOCK, FD_CLOEXEC);
		fcntl(pipe_stdout[0], F_SETFL, O_NONBLOCK, FD_CLOEXEC);
		this->cgiPid = pid;
		this->postData = postData + "\0";
		cgiState = WRITE_TO_CGI;
		std::cout << "URI:::" << uri <<std::endl;
		std::cout << "postData :: " << postData.substr(0, 100) << std::endl;
		scheduleWrite(pipe_stdin[1], postData);
		scheduleRead(pipe_stdout[0]);
		IOServer::getInstance().subscribe_processdie(cgiPid, this); //추가한부분
		// IOServer::getInstance().subscribe_processdie(cgiPid, this); //프로세스 죽이기 구독. 주석 나중에 풀어야함
	} else {
		std::cerr << " Request : Failed to fork for CGI script" << std::endl;
	}
}

void Request::processCgi() {
	switch (cgiState) {
		case WRITE_TO_CGI:
			break;
		case READ_FROM_CGI:
			break;
		case PROCESS_CGI_OUTPUT:
			//sendHttpResponse(client_socket, "200 OK", scriptOutput);
			if (scriptOutput.empty())
				scriptOutput = " ";
			sendHttpResponseCgi("200 OK", scriptOutput);
			cgiState = CGI_COMPLETED;
			break;
		case CGI_COMPLETED:
			break;
		default:
			break;
	}
}

void Request::handleKevent(uintptr_t fd, std::string type, struct kevent * event){
    this->self_event = event;

    {std::cout << "Request "<< this <<" ::" <<"handleKevent() start with fd ="<< fd << " type ="<<type << std::endl;}

	if (this->self_event->fflags & EV_ERROR) {
		sendResponse("500 Not Implemented", "Not Implemented");
		return;
	}

    if (type == "write") {
    {std::cout << "Request "<< this <<" ::" <<"handleKevent()  in write with postdata.size ="<<postData.size() << std::endl;}
		if (event->flags & EV_EOF) {
			std::cerr << "Broken pipe detected fd :" << event->ident << std::endl;
			close(stdinfd);
			IOServer::getInstance().cancle_subscribe(stdinfd, "write", this);

			return ;
		}
		if (postData.size() == 0)
		{
			//write(stdinfd, "\0", 1);
			close(stdinfd);
			// kill(cgiPid, SIGKILL);
		}
        ssize_t bytesWritten = write(stdinfd, postData.c_str(), std::min((size_t)(self_event->data), postData.size()));
	    {std::cout << "Request "<< this <<" ::" <<"handleKevent()  bytesWritten = "<<bytesWritten << std::endl;}
	    
        if (bytesWritten > 0) {
                // 남은 데이터를 저장하고 다시 쓰기 스케줄
                //postData = postData.substr(bytesWritten);
                postData = postData.erase(0, bytesWritten);
				// scheduleWrite(stdinfd, postData);
        } else if (bytesWritten == 0) {
			if (postData.size() == 0)
			{
				
				cgiState = READ_FROM_CGI;
				{std::cout << "Request "<< this <<" ::" <<"handleKevent() write done " << std::endl;}
				
				close(stdinfd);
				cgiState = READ_FROM_CGI;
			}
			else
				scheduleWrite(stdinfd, postData);
		} else {
            // 에러 처리
			{std::cout << "Request "<< this <<" ::" << "handleKevent() write in fd Errno ::" << strerror(errno) << " :: fd =" << stdinfd << std::endl;}

        }
    } else if (type == "read") {
	    {std::cout << "Request "<< this <<" ::" <<"handleKevent()  in read" << std::endl;}
		
		char buffer[1024 * 1024];

        int bytesRead = 0;
		{
			bytesRead = read(stdoutfd, buffer,  std::min((size_t)(self_event->data) ,sizeof(buffer) - 1));
			// bytesRead = read(stdoutfd, readbuffer, sizeof(readbuffer) - 1);
			{std::cout << "Request "<< this <<" ::" <<"handleKevent()  bytesRead = "<<bytesRead << std::endl;}

			if (bytesRead > 0) {
				buffer[bytesRead] = '\0';
				scriptOutput += buffer;
			} else if (bytesRead == 0) { //조건문 <0 지우기 나중에
					{std::cout << "Request "<< this <<" ::" <<"handleKevent() stdoutfd closed " << std::endl;}
					cgiState = PROCESS_CGI_OUTPUT;
					processCgi();
					close(stdoutfd);
					IOServer::getInstance().cancle_subscribe(stdoutfd, "read", this);
					return;
			} else {
				std::cout << "error" << std::endl;
				return;
			}
		}

    } else if (type == "die")
	{
		std::cout << "DIE CALLED" << std::endl;
		waitpid(fd, 0, WNOHANG);
	}
}


// void Request::scheduleWrite(int fd, const std::string& data) {
//     {std::cout << "Request "<< this <<" ::" <<"handleKevent() subscribe write" << std::endl;}
// 	IOServer::getInstance().subscribe(fd, "write", this);
// 	this->postData = data;
// }

// void Request::scheduleWrite(int fd) {
//     {std::cout << "Request "<< this <<" ::" <<"handleKevent() subscribe write" << std::endl;}
// 	IOServer::getInstance().subscribe(fd, "write", this);
// }

// void Request::scheduleRead(int fd) {
//     {std::cout << "Request "<< this <<" ::" <<"handleKevent() subscribe read" << std::endl;}
// 	IOServer::getInstance().subscribe(fd, "read", this);
// }

void Request::scheduleWrite(int fd, const std::string& data) {
    {std::cout << "Request "<< this <<" ::" <<"handleKevent() subscribe write" << std::endl;}
	IOServer::getInstance().subscribe_ever(fd, "write", this);
	this->postData = data;
}

void Request::scheduleWrite(int fd) {
    {std::cout << "Request "<< this <<" ::" <<"handleKevent() subscribe write" << std::endl;}
	IOServer::getInstance().subscribe_ever(fd, "write", this);
}

void Request::scheduleRead(int fd) {
    {std::cout << "Request "<< this <<" ::" <<"handleKevent() subscribe read" << std::endl;}
	IOServer::getInstance().subscribe_ever(fd, "read", this);
}

// void Request::parseRequest() {
//     char buffer[1024];
//     std::string request;

//     // 클라이언트로부터 요청 데이터 수신
//     ssize_t bytesReceived = recv(client_socket, buffer, sizeof(buffer), 0);
//     if (bytesReceived < 1) {
//         // 에러 처리 추가. 그냥 리턴하면 되나? -> 그냥 리턴시 501 Not Implemented 에러 발생
//         return;
//     }

//     request.assign(buffer, bytesReceived);

//     std::istringstream requestStream(request);
//     std::string line;
//     std::getline(requestStream, line);

//     // 첫 줄에서 HTTP 메소드, URI, 프로토콜 버전 파싱
//     std::istringstream lineStream(line);
//     lineStream >> method >> uri >> protocolVersion;

//     // 헤더 파싱
//     while (std::getline(requestStream, line) && line != "\r") {
//         std::string::size_type colonPos = line.find(':');
//         if (colonPos != std::string::npos) {
//             std::string headerName = line.substr(0, colonPos);
//             std::string headerValue = line.substr(colonPos + 2);
//             headers[headerName] = headerValue;
//         }
//     }
//     // POST 요청의 경우, 본문 파싱
//     if (method == "POST" && requestStream.rdbuf()->in_avail() > 0) {
//         std::getline(requestStream, body, '\0');
//     }
// }

// void Request::handleGet() {
//     if (!isFileAccessible(file_path)) {
//         sendResponse("404 Not Found", "Requested file not found.");
//         return;
//     }

//     std::vector<char> data;
//     if (readFileContents(file_path, data)) {
//         sendHttpResponseGet(client_socket, data, "200 OK");
//     } else {
//         sendResponse("500 Internal Server Error", "Unable to read file.");
//     }
// }

void Request::handleGet() {
	std::vector<char> data;
	std::string default_error_page;
    if (!isFileAccessible(file_path)) { // -> 파일이 아니므로 경로인지 체크 // 경로 : 리스팅
		// default_error_page = server->errorPagePath(404);
		// readFileContents(default_error_page, data);
        // sendHttpResponseGet(client_socket, data, "404 Not Found");
        //sendHttpResponseGet(data, "404 Not Found");
		sendResponseError(404);

        return;
    }
    std::cout << "Request.handleGet : Path : " << file_path << std::endl;

	//cgi일 경우 cgi 처리. cgi에서 환경변수 (QUERY_STRING)을 읽어서 처리해야 함.
	std::string cgiPath = server->uri2CGIPath(uri);
    std::cout << "Request.handleGet : cgiPath : " << cgiPath << std::endl;
    if (cgiPath != "-isnotCGI") {
        //std::string cgiScriptPath = server->uri2path(uri); // CGI 스크립트 경로
        std::string cgiScriptPath = cgiPath; // CGI 스크립트 경로
        executeCgiScript(cgiScriptPath, body); // CGI 스크립트 실행
		return;
    }
	/*
	uri2path 로 경로를 받는다.
	경로가 폴더인지 파일인지 확인한다.
	1. 폴더일 경우
		리스팅이 켜져 있는지 확인한다. -> 켜져 있으면 리스팅을 제공한다.
		안 겨져있다면..
	2. 파일일 경우
		기존처럼 서빙한다.
	uri 서버 메소드에서 리스팅 켜져있는지 확인 가능
	*/
	DIR *dir;
	dir = opendir(file_path.c_str());

	if (dir != NULL) {
		closedir (dir);
		if (!isSlashEnd){
			sendResponseRedirect(uri+"/");
			return;
		}
		
	}


	// std::string tri_dl_path = server->tri_directoryListing.findLongestMatchingPath(file_path);
	bool is_dl = server->uri2directoryListing(uri);
	if (is_dl) {
		std::map<int, std::string> dl = DirectoryListing::getInstance().run(file_path);
		if (dl[1].empty()) {
			data = std::vector<char>(dl[2].begin(), dl[2].end());
			// sendHttpResponseHTML(client_socket, data, "200 OK");
			sendHttpResponseHTML(data, "200 OK");
			return;
		}
	}

    if (readFileContents(file_path, data)) {
        // sendHttpResponseGet(client_socket, data, "200 OK");
        sendHttpResponseGet(data, "200 OK");
    } else {
		default_error_page = server->errorPagePath(500);
		readFileContents(default_error_page, data);
        // sendHttpResponseGet(client_socket, data, "500 Internal Server Error");
        sendHttpResponseGet(data, "500 Internal Server Error");
    }
}

void Request::handlePost() {
    // 1. CGI 요청 확인
    std::string cgiPath = server->uri2CGIPath(uri);
	std::cout << "Request.handlePost : cgiPath : " << cgiPath << std::endl;

    if (cgiPath != "-isnotCGI" && server->uricanMethod(uri, "POST")) {
        //std::string cgiScriptPath = server->uri2path(uri); // CGI 스크립트 경로
		std::string cgiScriptPath = cgiPath; // CGI 스크립트 경로
        executeCgiScript(cgiScriptPath, body); // CGI 스크립트 실행
    }
    else {
		// 2. 일반 POST 요청 처리
        handleRegularPost();
    }
    // 3. 기타 처리 (예외 상황, 에러 처리 등)
    // ... 추가적인 예외 처리 및 에러 응답 로직
}

void Request::handleRegularPost() {
    std::string uploadPath = server->uri2path(uri);
	// 폴더인지 확인하세요
	// upload 의 경우 uri2uploadpath 함수를 가져와서 파일 위치를 지정하세요.
	std::cout << "Request.handleRegularPost : body.size() : " << body.size() << std::endl;
	std::cout << "Request.handleRegularPost : uri : " << uri << std::endl;

	// if (uri == "/post_body" && body.size() > 100)
	// {
	// 	sendResponse("413 Request Entity Too Large", "File size is too large.");
	// 	return ;
	// }
    if (!uploadPath.empty() && saveFile(uploadPath, body) && server->uricanMethod(uri, "POST")) {
        sendResponse("200 OK", "File uploaded successfully.");
    } else if (!uploadPath.empty() && postData.empty()) {
		sendResponse("411 Length Required", "Content-Length header is required.");
	} else if (uploadPath.empty() && !postData.empty()) {
		sendResponse("200 OK", postData);
	} else if (!saveFile(uploadPath, body)) {
		sendResponse("500 Internal Server Error", "Failed to save file.");
	}
        // sendResponse("405 Method Not Allowed", "Failed to upload file.");
}

void Request::handleDelete() {
	std::string filepath = server->uri2path(uri);

	if (remove(filepath.c_str()) == 0) {
		sendResponse("200 OK", "File deleted successfully.");
	} else {
		sendResponse("404 Not Found", "File not found.");
	}
}

void Request::sendResponse(const std::string& status, const std::string& content) {
	std::string response = "HTTP/1.1 " + status + "\r\n";
	response += "Content-Length: " + std::to_string(content.length()) + "\r\n";
	response += "Content-Type: text/plain\r\n";
	response += "\r\n";
	response += content;
	//response += "\r\n\r\n";

	// send(client_socket, response.c_str(), response.length(), 0);
	connection->addOutQueue(response);
	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);
	{std::cout << "Request.sendResponse : addoutqueue & delete_request" << std::endl;}
	{std::cout << "Request.sendResponse : content : "<< content << std::endl;}
}

// void Request::sendHttpResponseCgi(const std::string& status, const std::string& content) {

//     std::string responseHeader = "HTTP/1.1 " + status + "\r\n";
// 	responseHeader += "Content-Type: " + server->getMimeType(file_path) + "\r\n";
// 	responseHeader += "Transfer-Encoding: chunked\r\n";
// 	responseHeader += "\r\n";

// 	connection->addOutQueue(responseHeader);

// 	size_t position = 0;
// 	size_t chunkSize = 400000;
// 	std::string chunkResponse;


// 	while (position < content.length()) {
// 		size_t currentChunkSize = std::min(chunkSize, content.length() - position);
// 		// 청크 크기를 16진수 형태로 변환
// 		chunkResponse += intToHexString(currentChunkSize) + "\r\n";
// 		// 현재 청크의 데이터 추가
// 		chunkResponse += content.substr(position, currentChunkSize) + "\r\n";
// 		// 다음 청크 위치로 이동
// 		position += currentChunkSize;

// 		// 청크 데이터 전송
// 		connection->addOutQueue(chunkResponse);
// 		chunkResponse = "";
// 	}

// 	responseHeader = "0\r\n\r\n";
// 	connection->addOutQueue(responseHeader);

// 	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);
// 	{std::cout << "Request.sendHttpResponse : addoutqueue & delete_request" << std::endl;}

// }

void Request::sendHttpResponseCgi(const std::string& status, const std::string& content) {
	(void) status;
	
	// std::cout << "SENDTEXT" << std::endl;
	// std::cout << content.substr(0, 300) << std::endl;
    // std::string responseHeader = "HTTP/1.1 " + status + "\r\n";
	// responseHeader += "Content-Type: " + server->getMimeType(file_path) + "\r\n";
	// // responseHeader += "Transfer-Encoding: chunked\r\n";
	// responseHeader += "Content-Length: " + std::to_string(content.length()) + "\r\n";
	// std::cout << "Request.sendHttpResponseCgi : content.length() : " << content.length() << std::endl;
	// sleep(3);
	// // responseHeader += "Connection: keep-alive\r\n";
	// responseHeader += "\r\n";


	

	std::string toFind = "Status:";
	std::string replaceWith = "HTTP/1.1";
	std::string responseHeader;
	responseHeader += content;

	size_t position = responseHeader.find(toFind);
	if (position != std::string::npos) {
        responseHeader.replace(position, toFind.length(), replaceWith);
    }

	std::string temp;
    size_t pos = 0;
    int lineCount = 0;
	std::string str1 = responseHeader;
    // 처음 3줄 제거 및 temp에 추가
    while (lineCount < 2 && pos != std::string::npos) {
        size_t newPos = str1.find("\r\n", pos);
        if (newPos != std::string::npos) {
            temp += str1.substr(pos, newPos - pos + 2); // "\r\n" 포함
            pos = newPos + 2;
        } else {
            temp += str1.substr(pos) + "\r\n"; // 마지막 줄이면 "\r\n" 추가
            pos = newPos;
        }
        lineCount++;
    }
    str1.erase(0, pos);

	temp += "Content-Length: " + std::to_string(str1.size() - 2) + "\r\n";
	std::string combined = temp + str1;

	std::cout << "test2" << std::endl;
	std::cout << combined.substr(0, 300) << std::endl;
	connection->addOutQueue(combined);
	// kill(cgiPid, SIGKILL);
	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);
	{std::cout << "Request.sendHttpResponse : addoutqueue & delete_request" << std::endl;}

}

std::string Request::intToHexString(size_t value) {
    std::stringstream ss;
    ss << std::hex << value;
    return ss.str();
}
// void Request::sendHttpResponse(int client_socket, const std::string& status, const std::string& content) {
void Request::sendHttpResponse(const std::string& status, const std::string& content) {

    std::string response = "HTTP/1.1 " + status + "\r\n";

    response += "Content-Length: " + std::to_string(content.length()) + "\r\n"; //아래 줄이랑 순서 바꿔야함? 
    response += "Content-Type: " + server->getMimeType(file_path) + "\r\n"; // filepath 혹은 mimeType입력
    response += "\r\n";

    response += content; //cgi는 어떻게 보내야 함?
	//response += "\r\n\r\n";
    // send(client_socket, response.c_str(), response.length(), 0);
    connection->addOutQueue(response);
	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);
	{std::cout << "Request.sendHttpResponse : addoutqueue & delete_request" << std::endl;}

}

// void Request::sendHttpResponseGet(int client_socket, const std::vector<char>& data, const std::string& status) {
void Request::sendHttpResponseGet(const std::vector<char>& data, const std::string& status) {
	std::ostringstream response;
	response << "HTTP/1.1 " << status << "\r\n";
	response << "Content-Length: " << data.size() << "\r\n";
	response << "Content-Type: "+ server->getMimeType(file_path) + "\r\n"; // MIME 타입에 따라 변경
	response << "\r\n";

	response.write(&data[0], data.size());
	std::string full_response = response.str();
	// full_response += "\r\n\r\n";
	// std::string response_header = response.str();
	// send(client_socket, response_header.c_str(), response_header.size(), 0);
	// send(client_socket, &data[0], data.size(), 0);
	connection->addOutQueue(full_response);
	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);
	{std::cout << "Request.sendHttpResponseGet : addoutqueue & delete_request" << std::endl;}
}

// // void Request::sendHttpResponseGet(int client_socket, const std::vector<char>& data, const std::string& status) {
// void Request::sendResponseWithFile(const std::string filepath, const std::string& status) {
// 	std::ostringstream response;
// 	response << "HTTP/1.1 " << status << "\r\n";
// 	response << "Content-Length: " << data.size() << "\r\n";
// 	response << "Content-Type: "+ server->getMimeType(file_path) + "\r\n"; // MIME 타입에 따라 변경
// 	response << "\r\n";

// 	response.write(&data[0], data.size());
// 	std::string full_response = response.str();
// 	// full_response += "\r\n\r\n";
// 	// std::string response_header = response.str();
// 	// send(client_socket, response_header.c_str(), response_header.size(), 0);
// 	// send(client_socket, &data[0], data.size(), 0);
// 	connection->addOutQueue(full_response);
// 	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);
// 	{std::cout << "Request.sendHttpResponseGet : addoutqueue & delete_request" << std::endl;}
// }


void Request::sendResponseWithFile(const std::string filepath)
{
	std::string contents;
	std::ostringstream response;


	response << "HTTP/1.1 " << "200" << "OK" << "\r\n";

	if (isFileAccessible(filepath))
	{
		std::ifstream fs(filepath);
		std::ostringstream ss;
		ss << fs.rdbuf();
		contents = ss.str();
		response << "Content-Type: " + server->getMimeType(filepath) + "\r\n"; // MIME 타입에 따라 변경
	}
	else
	{
		sendResponseError(404);
		return;
	}

	response << "Content-Length: " << contents.size() << "\r\n";
	response << "\r\n";
	response << contents;

	connection->addOutQueue(response.str());
	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);


	{std::cout << "Request.sendHttpResponseGet : addoutqueue & delete_request" << std::endl;}

}

// // void Request::sendHttpResponseGet(int client_socket, const std::vector<char>& data, const std::string& status) {
void Request::sendResponseError(int code) {

	std::string path = this->server->errorPagePath(code);
	std::string contents;
	std::ostringstream response;


	response << "HTTP/1.1 " << code << " " << this->server->code2status(code) << "\r\n";

	if (path == "-useDefualt" || !isFileAccessible(path))
	{
		contents = server->defaultErrorPage(code);
		// 기본 에러페이지 전송
		response << "Content-Type: " << "text/html" << "\r\n"; // MIME 타입에 따라 변경
		
	} else {
		std::ifstream fs(path);
		std::ostringstream ss;
		ss << fs.rdbuf();
		contents = ss.str();
		response << "Content-Type: " + server->getMimeType(path) + "\r\n"; // MIME 타입에 따라 변경
	}

	response << "Content-Length: " << contents.size() << "\r\n";

	response << "\r\n";
	response << contents;

	connection->addOutQueue(response.str());
	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);


	{std::cout << "Request.sendHttpResponseGet : addoutqueue & delete_request" << std::endl;}
}


void Request::sendResponseRedirect(std::string new_uri) {

	std::string contents;
	std::ostringstream response;


	response << "HTTP/1.1 " << 301 << " " << this->server->code2status(301) << "\r\n";
	response << "Location: "<< new_uri;
	response << "\r\n\r\n";

	connection->addOutQueue(response.str());
	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);


	{std::cout << "Request.sendHttpResponseGet : addoutqueue & delete_request" << std::endl;}
}



// void Request::sendHttpResponseHTML(int client_socket, const std::vector<char>& data, const std::string& status) {
void Request::sendHttpResponseHTML(const std::vector<char>& data, const std::string& status) {
	std::ostringstream response;
	response << "HTTP/1.1 " << status << "\r\n";
	response << "Content-Length: " << data.size() << "\r\n";
	response << "Content-Type: text/html" << "\r\n"; // MIME 타입에 따라 변경
	response << "\r\n";

	response.write(&data[0], data.size());
	std::string full_response = response.str();
	// full_response += "\r\n\r\n";
	// std::string response_header = response.str();
	// send(client_socket, response_header.c_str(), response_header.size(), 0);
	// send(client_socket, &data[0], data.size(), 0);
	connection->addOutQueue(full_response);
	IOServer::getInstance().deliverEvent(reinterpret_cast<uintptr_t>(this), "delete_request", connection);
	{std::cout << "Request.sendHttpResponseGet : addoutqueue & delete_request" << std::endl;}
}


    // 초기화용 세터 메서드
void Request::initialize(const std::string& request_str, int code) {
//void Request::initialize(const std::string& request_str, std::string default_server) {
	{std::cout << "Request.initialize  start" << std::endl;}
	{std::cout << "Request.initialize string = "<< request_str.substr(0,10000) << std::endl;}
	std::istringstream requestStream(request_str);
	std::string line;
	std::getline(requestStream, line);
	while (line.size() < 3)
		std::getline(requestStream, line);

	// 기본 상황 fdㅊ
	stdinfd = STDIN_FILENO;
	stdoutfd = STDOUT_FILENO;

	this->error_code = code;
	{std::cout << "Request.initialize  errorcode = " << this->error_code << std::endl;}
	
	
	// 첫 줄에서 HTTP 메소드, URI, 프로토콜 버전 파싱
	std::istringstream lineStream(line);
	{std::cout << "Request.initialize getMethod line =  " << line << std::endl;}

	lineStream >> method >> uri >> protocolVersion;
	{std::cout << "Request.initialize  method : " << method << " uri : " << uri << " protocolVersion : " << protocolVersion << std::endl;}


	// 헤더 파싱
	while (std::getline(requestStream, line) && line != "\r") {
		{std::cout << "Request.initialize parse : getline =  " << line << std::endl;}
		trim(line);
		std::string::size_type colonPos = line.find(':');
		if (colonPos != std::string::npos) {
			std::string headerName = line.substr(0, colonPos);
			std::string headerValue = line.substr(colonPos + 2);
			headers[headerName] = headerValue;
			// headers.insert(headerName, headerValue);
			{std::cout << "Request.initialize header : " << headerName <<"="<< headers[headerName] << std::endl;}
			
		}
	}
	// std::vector<std::string> httpHeaders;
	// 	for (std::map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it) {
	// 		std::string headerKey = "HTTP_" + it->first;
	// 		std::replace(headerKey.begin(), headerKey.end(), '-', '_');
	// 		std::transform(headerKey.begin(), headerKey.end(), headerKey.begin(), ::toupper);
	// 		httpHeaders.push_back(headerKey + "=" + it->second);
	// 	}

	// FL(i, httpHeaders.size()){std::cout << "Request.initialize HEADERS : " << httpHeaders[i] << std::endl;}

	//할일 : 서버 넣어주기
	this->server = connection->get_default_server();
	//Listener::getInstance().findServer("0.0.0.0", 8081, "default");

	// host 헤더를 보고 적절한 서버 찾아가기
		// 에러 응답의 경우는 connection이 기본 서버와 매칭
	// {std::cout << "아직 안 찾음" << std::endl;}

	std::map<std::string, std::string>::iterator it= headers.find("Host");	
	// {std::cout << "이터레이터 돌림" << std::endl;}

	if (it != headers.end() && !this->error_code) {//에러 응답의 경우는 connection이 기본 서버와 매칭
		std::string request_host = it->second;
		
		// {std::cout << "이터레이터 찾음" << std::endl;}


		//일단 host가 IP뿐이라고 가정하고 
		try	{this->server = Listener::getInstance().findServer(request_host+":80", "default"); goto endpoint;}
		catch (std::exception e) {std::cout << e.what() << std::endl;}

		// {std::cout << "설마 기본 포트가 여기로 잡히겠어?" << std::endl;}

		//다음으로 host가 IP와 포트라고 가정하고 
		try	{this->server = Listener::getInstance().findServer(request_host, "default");  goto endpoint;}
		catch (std::exception e) {std::cout << e.what() << std::endl;}
		
		// {std::cout << "설마 기본 포트가 이런데 잡히겠어?" << std::endl;}

		//다음으로 host가 name이라고 가정하고
		try	{this->server = Listener::getInstance().findServer(server->getServerName()[0], server->getPort(), request_host);}
		catch (std::exception e) {std::cout << e.what() << std::endl;}

		// {std::cout << "설마 이름이 이것도 안 잡히겠어?" << std::endl;}

	}
	endpoint:

	//uri를 가지고 미리 file path를 계산하기
	std::string decoded_uri = decodeURIComponent(uri);
	size_t question_mark = decoded_uri.find("?");
	if (question_mark != std::string::npos) {
		this->queryString = decoded_uri.substr(question_mark);
		decoded_uri = decoded_uri.substr(0,question_mark);
	}


	if (decoded_uri.size() > 0 && *(decoded_uri.end() - 1) == '/' && (decoded_uri.end()-1 != decoded_uri.begin()))
	{
		isSlashEnd = true;
		decoded_uri.erase(decoded_uri.end() - 1);
	}
	this->file_path = this->server->uri2path(decoded_uri);
	this->uri = decoded_uri;
	{std::cout << "uri ====== " << uri << std::endl;}
	{std::cout << "path ====== " << this->file_path << std::endl;}

	// POST 요청의 경우, 본문 파싱
	// if (method == "POST" && requestStream.rdbuf()->in_avail() > 0) {
	// 	std::getline(requestStream, body, '\0');
	// }
	std::string requestData =requestStream.str();
	std::string::size_type pos = requestData.find("\r\n\r\n");
	if (pos != std::string::npos) {
		this->body = requestData.substr(pos + 4);
	} else {
		body.clear();
	}
	//{std::cout << "Request.initialize Body : "<< this->body << std::endl;}
	{std::cout << "Request.initialize Body 1000 : "<< this->body.substr(0, 1000) << std::endl;}

	// request 처리 시작
	// processRequest();


	// 만약 connection 헤더가 close 면 연결 종료 요청
	std::map<std::string, std::string>::iterator it2 = headers.find(headers["Connection"]);	
	if (it2 != headers.end() && !this->error_code) {
		if (it2->second == "close") IOServer::getInstance().deliverEvent(uintptr_t(this), "shutdown_connection", connection);
	}

	std::map<std::string, std::string>::iterator it4 = headers.begin();
	{std::cout << "Request.initialize headers: " << std::endl;}
	while (it4 != headers.end())
	{
		{std::cout << it4->first << "=" << it4->second << std::endl;}
		it4++;
	}
	
	//실험
	//IOServer::getInstance().deliverEvent(uintptr_t(this), "shutdown_connection", connection);



	// 초기화 끝
	{std::cout << "Request.initialize end" << std::endl;}

}

bool Request::isFileAccessible(const std::string& filepath) {
    std::ifstream file(filepath.c_str());
    return file.good();
}

// 파일 저장 함수 여기서부터 아래 수정
bool Request::saveFile(const std::string& filepath, const std::string& data) {
    std::ofstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }
    file.write(data.c_str(), data.size());
	file.close();
    return true;
}

// 파일 업로드 처리 함수
void Request::handleFileUpload(const std::string& requestHeaders, const std::string& requestBody) {
    // Content-Type 검사 (예: "image/png")
    std::string expectedContentType = server->getMimeType(file_path);
    if (requestHeaders.find("Content-Type: " + expectedContentType) == std::string::npos) {
        // 잘못된 파일 타입 처리
        return;
    }

    // 파일 저장
    std::string filename = "/path/to/save/uploaded_file.png"; // 저장할 파일 이름 설정 uri?
    if (!saveFile(filename, requestBody)) {
        // 파일 저장 실패 처리
    }
}


std::string Request::decodeURIComponent(const std::string& encoded) {
    std::string result;
    std::istringstream stream(encoded);
    char ch;

    while (stream.get(ch)) {
        if (ch == '%') {
            int value;
            stream >> std::hex >> value; // 16진수로 읽음
            result += static_cast<char>(value);
            //stream.ignore(); // '%' 뒤의 두 문자를 무시
        
		//타입이 application/x-www-form-urlencoded 인 경우에는 +를 공백으로 치환해야 함
		// } else if (ch == '+') {
        //     result += ' ';
        
		} else {
            result += ch;
        }
    }

    return result;
}



