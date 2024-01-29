#include "Listener.hpp"
#include "Connection.hpp"
#include <cstring>
#include <stdexcept>
#include "DEBUG.hpp"

#include "Utils.hpp"

// static void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t			a;
// 	unsigned char	d;
// 	unsigned char	*e;

// 	a = 0;
// 	e = (unsigned char *) b;
// 	d = (unsigned char) c;
// 	while (a < len)
// 	{
// 		e[a] = d;
// 		a++;
// 	}
// 	return (b);
// }



static void printServerMap(const std::map<std::string, std::map<std::string, Server*> >& servers) {
    for (std::map<std::string, std::map<std::string, Server*> >::const_iterator groupIt = servers.begin(); groupIt != servers.end(); ++groupIt) {
        std::cout << "host: " << groupIt->first << std::endl;
        const std::map<std::string, Server*>& serverMap = groupIt->second;
        for (std::map<std::string, Server*>::const_iterator serverIt = serverMap.begin(); serverIt != serverMap.end(); ++serverIt) {
            std::cout << "  ServerName: " << serverIt->first;
            if (serverIt->second != NULL) {
                std::cout << ", Server Pointer: " << serverIt->second;
            } else {
                std::cout << ", No Server";
            }
            std::cout << std::endl;
        }
    }
}


// struct sockaddr_in parse_address(const std::string& address) {
//     struct sockaddr_in addr;
//     ft_memset(&addr, 0, sizeof(addr)); // 구조체 초기화

//     addr.sin_family = AF_INET; // 주소 패밀리 설정

//     std::istringstream addr_stream(address);
//     std::string ip;
//     int port;

//     // ':' 기준으로 문자열을 IP 주소와 포트로 나눕니다.
//     if (getline(addr_stream, ip, ':') && (addr_stream >> port)) {
//         // IP 주소와 포트 번호 추출
//         if (inet_pton(AF_INET, ip.c_str(), &addr.sin_addr) <= 0) {
//             std::cerr << "Invalid IP address" << std::endl;
//             exit(EXIT_FAILURE);
//         }
//         addr.sin_port = htons(port); // 포트 번호 설정
//     } else {
//         std::cerr << "Invalid address format" << std::endl;
//         exit(EXIT_FAILURE);
//     }

//     return addr;
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

Listener& Listener::getInstance() {
    static Listener l;
    return l;
}

Listener::Listener() {
    will_shutdown = false;
    fd_count = 0;
}

//void Listener::handleKevent(uintptr_t fd, std::string type) {
void Listener::handleKevent(uintptr_t fd, std::string type, struct kevent * event){
    this->self_event = event;
    {std::cout << "Lister handleKevent callbacked --fd:" << fd << " --type: " << type << std::endl;}
    if (type == "read") make_connection(fd); // 형 변환 명시 필요
    //else if (type == "write") make_connection(fd);
    else    return ; //error handler
}

void Listener::handleMessage(uintptr_t fd, std::string message) {
    std::cout << "Listener : handleMessage called : " << message << std::endl;
    if (message == "delete_connection") delete_connection(fd);
    //if (message == "")
}

void Listener::addServer(const std::string& IP, int port, const std::string& serverName, Server* server) {
    { std::cout << "Listener.addServer : " << IP << " " << port << " " << serverName << std::endl; }
    servers[IP + ":" + std::to_string(port)][serverName] = server;
    
    //set default server automaticaly
    if (servers[IP + ":" + std::to_string(port)].size() == 1) 
        servers[IP + ":" + std::to_string(port)]["default"] = server;
}

Server* Listener::findServer(const std::string& IP, int port, const std::string& serverName) {
    {std::cout << "Listener.findServer : to find "<< (IP + ":" + std::to_string(port)) << " " << serverName << "0" << std::endl;}
    {printServerMap(servers);}

    if (servers.find(IP + ":" + std::to_string(port)) != servers.end()) {
        std::map<std::string, Server*>& serverMap = servers[IP + ":" + std::to_string(port)];
        // {std::cout << "Listener.findServer : serverMap size = " << serverMap.size() << std::endl;}
        std::map<std::string, Server*>::iterator it = serverMap.find(serverName);
        // {std::cout << "Listener.findServer : serverMap.find(serverName) = " << it->first << std::endl;}
        if (it != serverMap.end()) {return it->second;}
        // 서버를 찾지 못할 경우 기본 서버를 반환
        throw std::runtime_error("Listener::findServer :: cannot find host");
        // return servers[IP + ":" + std::to_string(port)]["default"];
    }
    throw std::runtime_error("Listener::findServer :: cannot find host");
}

// Server* Listener::findServer(const std::string& IP, int port, const std::string& serverName) {
//     std::string address = IP + ":" + std::to_string(port);
//     std::cout << "Listener.findServer : to find " << address << " " << serverName << std::endl;
//     printServerMap(servers);

//     std::map<std::string, Server*>::iterator addrIt = servers.find(address);
//     if (addrIt != servers.end()) {
//         std::map<std::string, Server*>& serverMap = addrIt->second;
//         std::cout << "Listener.findServer : serverMap size = " << serverMap.size() << std::endl;

//         for (std::map<std::string, Server*>::iterator it = serverMap.begin(); it != serverMap.end(); ++it) {
//             if (it->first == serverName) {
//                 std::cout << "Listener.findServer : Found serverName = " << it->first << std::endl;
//                 return it->second;
//             }
//         }

//         throw std::runtime_error("Listener::findServer :: cannot find server for name: " + serverName);
//     } else {
//         throw std::runtime_error("Listener::findServer :: cannot find host for address: " + address);
//     }
// }

// Server* Listener::findServer(const std::string& host, const std::string& serverName) {
//     {std::cout << "Listener.findServer : to find "<< host << " " << serverName << std::endl;}
//     {printServerMap(servers);}

//     if (servers.find(host) != servers.end()) {
//         std::map<std::string, Server*>& serverMap = servers[host];
//         std::map<std::string, Server*>::iterator it = serverMap.find(serverName);
//         if (it != serverMap.end()) {return it->second;}
//         // 서버를 찾지 못할 경우 기본 서버를 반환
//         return servers[host]["default"];
//     }
//     throw std::runtime_error("cannot find host");
// }

Server* Listener::findServer(const std::string& host, const std::string& serverName) {
    std::cout << "Listener.findServer : to find " << host << " " << serverName << std::endl;
    printServerMap(servers);

    std::map<std::string, std::map<std::string, Server*> >::iterator hostIt = servers.find(host);
    if (hostIt != servers.end() && host.size() == hostIt->first.size()) {
        std::map<std::string, Server*>& serverMap = hostIt->second;
        std::map<std::string, Server*>::iterator it = serverMap.find(serverName);
        if (it != serverMap.end()) {
            return it->second;
        }
        // 서버를 찾지 못할 경우 기본 서버를 반환
        throw std::runtime_error("Host not found");
        // return serverMap["default"];
    }
    throw std::runtime_error("Host not found");
}


void Listener::listen_server() {
    std::map<std::string, std::map<std::string, Server*> >::iterator iter = servers.begin();
    while (!(iter == servers.end()))
    {
        {
            /* init server socket and listen */
            int server_socket;
            struct sockaddr_in server_addr;

            // 소켓 생성, 실패 시 에러 메시지 출력 후 종료
            if ((server_socket = socket(PF_INET, SOCK_STREAM, 0)) == -1)
                throw std::runtime_error("Listener::listen_server() : cannot make socket error\n");
            
            // 주소 구조체 초기화
            server_addr = string_to_address(iter->first);

            // 소켓에 주소 바인딩, 실패 시 에러 메시지 출력 후 종료
            if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
                throw std::runtime_error("Listener::listen_server() : bind() error\n"/* + std::string(strerror(errno))*/);

            // 소켓을 수신 대기 상태로 변경, 실패 시 에러 메시지 출력 후 종료
            if (listen(server_socket, 130) == -1)
                throw std::runtime_error("Listener::listen_server() : error\n"/* + std::string(strerror(errno))*/);

            // 소켓을 비블로킹 모드로 설정
            fcntl(server_socket, F_SETFL, O_NONBLOCK, FD_CLOEXEC); //CLOEXEC

            IOServer::getInstance().subscribe_ever(server_socket, "read", this);
            {std::cout << "Lister subscrib <read> on" << iter->first << " fd: " << server_socket << std::endl;}

            //fd에 열린 소켓의 host를 매핑
            sockets[server_socket] = iter->first;
            fd_count++;

            //DEBUG_EXEC(std::cout << "server listening on " << iter->first << std::endl;)
            
            {std::cout << "server listening on " << iter->first << std::endl;}
        }

        iter++;
    }
}

void Listener::make_connection(int fd) {
    while(true){
        {std::cout << "Listener.make_connection : start" << std::endl;}

        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        //int new_socket = accept(fd, &client_addr, &client_addr_len);
        int new_socket = accept(fd, (struct sockaddr *) &client_addr, &client_addr_len);

        if (new_socket == -1) //throw 
        {
            {std::cout << "Listener.make_connection : cannot accept" << std::endl;}
            return;
        }
        
        fcntl(new_socket, F_SETFL, O_NONBLOCK, FD_CLOEXEC); //CLOEXEC

        // long long bsize = 120000;
        // // getsockopt(new_socket, SOL_SOCKET, SO_SNDBUF, &bsize, (socklen_t *) sizeof(bsize));
        // // {std::cout << "bsize ======" << bsize << std::endl; }
        // setsockopt(new_socket, SOL_SOCKET, SO_SNDBUF, &bsize, sizeof(bsize));

        Server * default_server = findServer(sockets[fd], "default");

        //열린 파일이 너무 많은 경우 정리
        if (1200 < fd_count) {
            std::map<int, Connection *>::iterator it = connections.begin();
            while (it != connections.end())
            {
                (it->second)->shell_it_shutdown();
            }
        }

        //Connection * a = new Connection(new_socket, default_server);
        connections[new_socket] = new Connection(new_socket, default_server, client_addr);
        {std::cout << "Lister : new connection : " << connections[new_socket] << std::endl;}
        fd_count++;
    }
}

void Listener::delete_connection(int fd) {
    delete (connections[fd]);
    connections.erase(fd);
    fd_count--;
}

void Listener::check_shutdown() {
    if (will_shutdown && connections.empty()) {
        exit(0); // 자신의 소멸자 호출 or exit() 수정수정 );
    }
}

void Listener::shutdown_self() {
    //열려있는 모든 listen 소켓을 닫는다.
    std::map<int, std::string>::iterator server_socket = sockets.begin();
    while (server_socket != sockets.end()) 
    {
        close(server_socket->first);
        server_socket++;
        
    }
    sockets.clear();

    // Step 2: 모든 Connection 객체에 종료 요청 메시지 보내기
    std::map<int, Connection*>::iterator connect = connections.begin();
    
    while (connect != connections.end()) 
    {
        IOServer::getInstance().deliverEvent(0, "shutdown_request", (IOClient *) &(*connect));
        connect++;
    }

    return;
}

Listener::~Listener() {
    // 구현 내용
}

