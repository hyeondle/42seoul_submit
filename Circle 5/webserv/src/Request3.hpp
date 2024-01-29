//깔끔하게 바꿈

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "Connection.hpp"
#include "RequestUtils.hpp"
#include "IOServer.hpp"
#include "Listener.hpp"
// #include "Listener.hpp"

class Connection;

enum CgiState {
	IDLE,
	WRITE_TO_CGI,
	READ_FROM_CGI,
	PROCESS_CGI_OUTPUT,
	CGI_COMPLETED
};

// class RequestWrapper : public IOClient {
// public:
// 	RequestWrapper(Request* request) : request(request) {}

// 	void handleKevent(uintptr_t fd, std::string type) {
// 		if (request) {
// 			request->handleKevent(fd, type);
// 		}
// 	}
// 	void handleMessage(uintptr_t fd, std::string type) {
// 		return ;
// 	}

// private:
// 	Request* request;
// };

// class Listener : public IOClient {
// public:
// 	static Listener& getInstance();
// };

class Request : public IOClient{
public:
	Request(int client_socket, Connection* connection);
	// ~Request();
	void processRequest();
	//해당 메소드는 어떻게 처리해야할지..
	//virtual void handleKevent(uintptr_t fd, std::string type);
	virtual void handleMessage(uintptr_t uintptr_request, std::string message);
	virtual void handleKevent(uintptr_t fd, std::string type, struct kevent * event);
	// Cgi관련
	void executeCgiScript(const std::string& scriptPath, const std::string& postData);
	void processCgi();
	void scheduleWrite(int fd, const std::string& data);
	void scheduleRead(int fd);

	// 요청 관련
	void handleGet();
	void handlePost();
	void handleDelete();
	void parseRequest();

	// 응답을 string 타입으로 이벤트큐에 저장
	void sendResponse(const std::string& status, const std::string& content);
	// void sendHttpResponseGet(int client_socket, const std::vector<char>& data, const std::string& status);
	// void sendHttpResponseHTML(int client_socket, const std::vector<char>& data, const std::string& status);
	// void sendHttpResponse(int client_socket, const std::string& status, const std::string& content);
	void sendHttpResponseGet(const std::vector<char>& data, const std::string& status);
	void sendHttpResponseHTML(const std::vector<char>& data, const std::string& status);
	void sendHttpResponse(const std::string& status, const std::string& content);

    // 초기화용 세터 메서드
    void initialize(const std::string& request_str, int code);
	bool isFileAccessible(const std::string& filepath);

	bool saveFile(const std::string& filename, const std::string& data);
	void handleFileUpload(const std::string& requestHeaders, const std::string& requestBody);
	std::string getErrorStatus(int code);
	void handleRegularPost();

	void scheduleWrite(int fd);
	void sendHttpResponseCgi(const std::string& status, const std::string& content);
	void makeenv(const std::string &data);
	
	void sendResponseError(int code);
	void sendResponseWithFile(const std::string filepath);

	bool isSlashEnd;

	void sendResponseRedirect(std::string new_uri);

private:
	// 요청 처리 관련 변수
	int client_socket;
	Connection* connection;
	Server* server;
	CgiState cgiState;
	std::string file_path;
	std::string method;
	std::string uri;
	std::string protocolVersion;
	std::map<std::string, std::string> headers;
	std::string body;
	int pipe_stdin[2], pipe_stdout[2];
	pid_t cgiPid;
	std::string scriptOutput;
	std::string postData;
	int error_code;
	std::string queryString;

	std::string decodeURIComponent(const std::string& encoded);
	int stdinfd;
	int stdoutfd;
	std::string intToHexString(size_t value);

	std::map <std::string, std::string> envmap;
	char **envp;

	// char *readbuffer;
};

#endif