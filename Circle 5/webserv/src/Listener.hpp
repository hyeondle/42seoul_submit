#ifndef LISTENER_HPP
#define LISTENER_HPP

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <sys/socket.h> // 소켓 인터페이스
#include <arpa/inet.h> // 인터넷 주소 정의
#include <fcntl.h>

#include "IOClient.hpp"
// #include "Connection.hpp"

// 함수 선언
struct sockaddr_in parse_address(const std::string& address);

class Server;
class Connection;

class Listener : public IOClient {
private:
    Listener();
    std::map<int, Connection *> connections;
    std::map<int, std::string> sockets; 
    std::map<std::string, std::map<std::string, Server*> > servers;
    bool will_shutdown;
    int fd_count;

    void make_connection(int fd);   /*(<-- self)*/

public:
    static Listener& getInstance();

    //virtual void handleKevent(uintptr_t fd, std::string type);
    virtual void handleKevent(uintptr_t fd, std::string type, struct kevent * event);
    virtual void handleMessage(uintptr_t fd, std::string message);

    void addServer(const std::string& IP, int port, const std::string& serverName, Server* server);
    Server* findServer(const std::string& IP, int port, const std::string& serverName);
    Server* findServer(const std::string& host, const std::string& serverName);
    void listen_server();           /*(<-- main)*/
    void delete_connection(int fd); /*(<-- self <- IOServer <- Connection) : */
    void check_shutdown();          /*(<-- self <- IOServer <- Connection) : */
    void shutdown_self();

    ~Listener();
};

#endif // LISTENER_HPP

//             IOServer::getInstance().deliverEvent(0, "shutdown_request", (IOClient *) &(*connect));
//             connect++;
//         }

//         // Step 2: 모든 Connection 객체에 종료 요청 메시지 보내기
//         for (auto& pair : connections) {
//             pair.second.sendCloseMessage(); // 종료 메시지를 보내는 메서드
//         }

//         // Step 3: 모든 Connection이 종료될 때까지 대기
//         // 이 부분은 구현 방식에 따라 다를 수 있습니다. 예를 들어,
//         // 모든 Connection이 종료될 때까지 loop를 돌거나,
//         // 특정 조건이 충족될 때까지 대기할 수 있습니다.

//         // 마지막으로, connections 맵 정리
//         connections.clear();

//         // servers 맵 정리
//         for (auto& ip_port_pair : servers) {
//             for (auto& server_name_pair : ip_port_pair.second) {
//                 delete server_name_pair.second; // Server 객체 메모리 해제
//             }
//         }
//         servers.clear();
//     }

//     ~Listener() {
//         //순차적으로 돌며 커넥션, 소켓 지우고 닫기



//     }
// };


// #endif // LISTENER_H
