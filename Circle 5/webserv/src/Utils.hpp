#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include <netinet/in.h>

// Function declarations
void left_trim(std::string &s);
void right_trim(std::string &s);
void trim(std::string &s);
size_t convert_to_bytes(const std::string& number);
std::vector<std::string> string_to_tokens(std::string string);
struct sockaddr_in string_to_address(const std::string& address);
std::string address_to_string(const struct sockaddr_in& addr);

#endif // UTILS_HPP








// #ifndef UTILS_HPP
// #define UTILS_HPP

// #include <algorithm>
// #include <cctype>
// #include <locale>
// #include <sstream>
// #include <iostream>
// #include <string>

// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// // std::map<std::string, std::string> mimeTypeMap;

// // void setMimeTypeMap(std::map mimeTypeMap)
// // {
// //     mimeTypeMap[".txt"] = "text/plain";
// //     mimeTypeMap[".html"] = "text/html";
// //     mimeTypeMap[".css"] = "text/css";
// //     mimeTypeMap[".js"] = "application/javascript";
// //     mimeTypeMap[".json"] = "application/json";
// //     mimeTypeMap[".png"] = "image/png";
// //     mimeTypeMap[".jpg"] = "image/jpeg";
// //     mimeTypeMap[".jpeg"] = "image/jpeg";
// //     mimeTypeMap[".gif"] = "image/gif";
// //     mimeTypeMap[".svg"] = "image/svg+xml";
// //     mimeTypeMap[".ico"] = "image/x-icon";
// //     mimeTypeMap[".pdf"] = "application/pdf";
// //     mimeTypeMap[".mp3"] = "audio/mpeg";
// //     mimeTypeMap[".wav"] = "audio/wav";
// //     mimeTypeMap[".mp4"] = "video/mp4";
// //     mimeTypeMap[".woff"] = "font/woff";
// //     mimeTypeMap[".woff2"] = "font/woff2";
// //     mimeTypeMap[".ttf"] = "font/ttf";
// //     mimeTypeMap[".otf"] = "font/otf";
// //     mimeTypeMap[".eot"] = "application/vnd.ms-fontobject";
// //     mimeTypeMap[".sfnt"] = "application/font-sfnt";
// //     mimeTypeMap[".xml"] = "application/xml";
// //     mimeTypeMap[".swf"] = "application/x-shockwave-flash";
// //     mimeTypeMap[".flv"] = "video/x-flv";
// //     mimeTypeMap[".psd"] = "image/vnd.adobe.photoshop";
// //     mimeTypeMap[".ai"] = "application/postscript";
// //     mimeTypeMap[".eps"] = "application/postscript";
// //     mimeTypeMap[".ps"] = "application/postscript";
// //     mimeTypeMap[".doc"] = "application/msword";
// //     mimeTypeMap[".docx"] = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
// //     mimeTypeMap[".xls"] = "application/vnd.ms-excel";
// //     mimeTypeMap[".xlsx"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
// //     mimeTypeMap[".ppt"] = "application/vnd.ms-powerpoint";
// //     mimeTypeMap[".pptx"] = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
// //     mimeTypeMap[".odt"] = "application/vnd.oasis.opendocument.text";
// //     mimeTypeMap[".ods"] = "application/vnd.oasis.opendocument.spreadsheet";
// //     mimeTypeMap[".odp"] = "application/vnd.oasis.opendocument.presentation";
// //     mimeTypeMap[".odg"] = "application/vnd.oasis.opendocument.graphics";
// //     mimeTypeMap[".odc"] = "application/vnd.oasis.opendocument.chart";
// //     mimeTypeMap[".odb"] = "application/vnd.oasis.opendocument.database";
// //     mimeTypeMap[".odf"] = "application/vnd.oasis.opendocument.formula";
// //     mimeTypeMap[".odm"] = "application/vnd.oasis.opendocument.text-master";
// //     mimeTypeMap[".ott"] = "application/vnd.oasis.opendocument.text-template";
// //     mimeTypeMap[".ots"] = "application/vnd.oasis.opendocument.spreadsheet-template";
// //     mimeTypeMap[".otp"] = "application/vnd.oasis.opendocument.presentation-template";
// //     mimeTypeMap[".otg"] = "application/vnd.oasis.opendocument.graphics-template";
// //     mimeTypeMap[".otc"] = "application/vnd.oasis.opendocument.chart-template";
// //     mimeTypeMap[".otf"] = "application/vnd.oasis.opendocument.formula-template";
// //     mimeTypeMap[".oth"] = "application/vnd.oasis.opendocument.text-web";
// //     mimeTypeMap[".rtf"] = "application/rtf";
// //     mimeTypeMap[".jar"] = "application/java-archive";
// //     mimeTypeMap[".war"] = "application/java-archive";
// //     mimeTypeMap[".ear"] = "application/java-archive";
// //     mimeTypeMap[".hqx"] = "application/mac-binhex40";
// // }

// // std::string getMimeType(const std::string& filePath) {
// //     size_t dotPosition = filePath.rfind('.');
// //     if (dotPosition != std::string::npos) {
// //         std::string extension = filePath.substr(dotPosition);
// //         auto it = mimeTypeMap.find(extension);
// //         if (it != mimeTypeMap.end()) {
// //             return it->second;
// //         }
// //     }
// //     return "application/octet-stream";
// // }

// // trim from start (in place)
// void left_trim(std::string &s) 
// {
//     std::string::iterator it = s.begin();
//     while (it != s.end() && std::isspace(*it))
//         it++;
//     s.erase(s.begin(), it);
// }

// // trim from end (in place)
// // static inline std::string right_trim(std::string &s) {
// //     std::string::const_reverse_iterator rit = s.rbegin();
// //     while (rit != s.rend() && isspace(*rit)) 
// //     {
// //         rit++;
// //     }
// //     return std::string(s.begin(), rit.base());
// // }

// // // trim from end (in place)
// // static inline std::string right_trim(std::string &s) {
// //     std::string::const_iterator rit = s.end();
// //     while (rit != s.begin() && isspace(*rit)) 
// //     {
// //         rit--;
// //     }
// //     return std::string(s.begin(), rit.base());
// // }

// void right_trim(std::string &s)
// {
//     std::string::reverse_iterator rit = s.rbegin();
//     while (rit != s.rend() && std::isspace(*rit))
//         rit++;
//     s.erase(rit.base(), s.end());
// }

// // trim from both ends (in place)
// void trim(std::string &s) {
// 	left_trim(s);
// 	right_trim(s);
// }

// size_t convert_to_bytes(const std::string& number) {
// 	try {
// 		return std::stoull(number);
// 	} catch (const std::invalid_argument&) {
// 		size_t result = std::stoull(number.substr(0, number.size() - 1));
// 		switch(std::toupper(number.back())) {
// 			case 'K':
// 				result *= 1024;
// 				break;
// 			case 'M':
// 				result *= 1024 * 1024;
// 				break;
// 			case 'G':
// 				result *= 1024 * 1024 * 1024;
// 				break;
// 			default:
// 				 std::runtime_error("Invalid size unit");
// 		}
// 		return result;
// 	}
// }

// std::vector<std::string> string_to_tokens(std::string string) {
// 	::trim(string);
// 	std::vector<std::string> tokens;
// 	std::string token;
// 	std::istringstream iss(string);
// 	while (iss >> token) tokens.push_back(token);
// 	return tokens;
// }



















// struct sockaddr_in string_to_address(const std::string& address) {
//     struct sockaddr_in addr;
//     ft_memset(&addr, 0, sizeof(addr)); // 구조체 초기화

//     addr.sin_family = AF_INET; // 주소 패밀리 설정

//     std::istringstream addr_stream(address);
//     int segment;
//     char dot;
//     uint32_t ip_addr = 0;

//     for (int shift = 24; shift >= 0; shift -= 8) {
//         if (!(addr_stream >> segment) || segment < 0 || segment > 255 || (shift > 0 && addr_stream >> dot && dot != '.')) {
//             std::cerr << "Invalid IP address format" << std::endl;
//             exit(EXIT_FAILURE);
//         }
//         ip_addr |= segment << shift;
//     }

//     int port;
//     if (addr_stream >> dot && dot == ':' && addr_stream >> port) {
//         addr.sin_port = htons(port); // 포트 번호 설정
//     } else {
//         std::cerr << "Invalid port format" << std::endl;
//         exit(EXIT_FAILURE);
//     }

//     addr.sin_addr.s_addr = htonl(ip_addr);

//     return addr;
// }


// std::string address_to_string(const struct sockaddr_in& addr) {
//     uint32_t ip_addr = ntohl(addr.sin_addr.s_addr);  // 네트워크 바이트 순서를 호스트 바이트 순서로 변환
//     int port = ntohs(addr.sin_port);  // 네트워크 바이트 순서로 된 포트를 호스트 바이트 순서로 변환

//     std::stringstream ss;
//     ss << ((ip_addr >> 24) & 0xFF) << '.';  // 첫 번째 바이트
//     ss << ((ip_addr >> 16) & 0xFF) << '.';  // 두 번째 바이트
//     ss << ((ip_addr >> 8) & 0xFF) << '.';   // 세 번째 바이트
//     ss << (ip_addr & 0xFF);                 // 네 번째 바이트
//     ss << ':' << port;                      // 포트

//     return ss.str();
// }




// #endif // UTILS_HPP