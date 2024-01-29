#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "IOClient.hpp"
#include "Server.hpp"
#include "IOServer.hpp"
#include "Request3.hpp"

#include <set>
#include <string>
#include <iostream>
#include <queue>
#include <sys/socket.h>

class Request;

class Connection : public IOClient {
private:
    int socket_fd;
    Server *default_server;
    std::set<Request*> activeRequests;
    //std::map<uintptr_t, Request*> activeRequests;
    bool will_shutdown;
    std::stringstream ss_buffer;
    std::queue<std::string> outqueue;
    struct sockaddr_in client_addr;
    //int active_request_count;

    Request* parsingRequest;

    // void processRequestWithLength(int length);
    // void processChunkedRequest();
    std::string find_complete_http_request(std::string& input);

    //int parse_state;
    // 1 : 기본 상태
    // 2 : 헤더가 파싱되어 저장됨
    // 3 : 본문이...
	//std::string body;
    //	std::map<std::string, std::string> headers;
    
    void read_data_to_buffer();
    int find_and_get_header();
    void clear_parsing_maps();
    void mini_process_connection();



public:
    //Connection(int socket, Server* server);
    Connection(int socket, Server* server, sockaddr_in client_addr);
    ~Connection();

    virtual void handleKevent(uintptr_t fd, std::string type, struct kevent * event);
    virtual void handleMessage(uintptr_t uintptr_request, std::string message);
    
    void shutdown_connection();
    void processConnection();
    Request* makeRequest(std::string str, int code);
    void delete_request(Request* request);
    void check_shutdown();
    void delete_connection();
    void sendResponse();
    void addOutQueue(std::string response);
	void instant_response(int num, std::string message);
    void shell_it_shutdown();

    std::string buffer;
    std::map<std::string, std::string> parsingMap;
    std::map<std::string, int>         parsingIntMap;


    std::string client_host();

    Server * get_default_server();
};

#endif // CONNECTION_HPP

