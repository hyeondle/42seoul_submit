#ifndef REQUESTUTILS_HPP
#define REQUESTUTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

std::string uriToFilepath(const std::string& uri);
bool readFileContents(const std::string& filepath, std::vector<char>& buffer);
//기본 block모드이므로, non-block 모드로 소켓 설정하거나 kqueue로 논블록 맞는지 체크 필요
bool receivePostData(int client_socket, std::string& data);

#endif // REQUESTUTILS_HPP