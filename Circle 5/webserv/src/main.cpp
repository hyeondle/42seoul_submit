/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:39:00 by snoh              #+#    #+#             */
/*   Updated: 2023/11/20 16:50:56 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include "Server.hpp"
#include "Listener.hpp"
#include "IOServer.hpp"
#include "Request3.hpp"
#include "RequestUtils.hpp"
#include <set>

void leaks() {system("pid=$(ps -p $$ -o ppid=); leaks $pid");}

bool is_ip(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it) && *it != '.') {
            return false;
        }
    }
    return true;
}

std::string get_ip_by_domain() {
    // 도메인 주소의 ip를 불러와야함
    return "0.0.0.0";
}

std::string get_ip(const std::string& str) {
    if (is_ip(str)) {
        { std::cout << "is ip : " << str << std::endl; }
        return str;
    } else {
        { std::cout << "is domain : " << str << std::endl; }
        return get_ip_by_domain();
    }
}

// // SIGPIPE 시그널 핸들러
// void handle_sigpipe(int sig) {
//     // 여기에서 SIGPIPE 시그널을 처리하는 로직을 구현할 수 있습니다.
//     std::cout << "Caught SIGPIPE" << std::endl;
// }


int main(int argc, char ** argv)
{
    //atexit(leaks);
    (void) argc;
    (void) argv;

    std::set<Server*> servers;

    try
    {
        // //시그널 핸들러 등록
        // if (signal(SIGPIPE, handle_sigpipe) == SIG_ERR) {
        //     throw(std::runtime_error("Can't catch SIGPIPE"));
        // // 에러 처리
        // }

        // 설정 파일 열고 파싱 시작.
        std::string file_name = (argc == 2) ? argv[1] : "default.conf";

        std::ifstream config_file(file_name);
        if (!config_file.is_open())
            throw std::runtime_error("main() : Can't open file: " + file_name);

        std::string line;
        // 서버가 나오면 서버 생성자에, &file 넣고 호출
        // 반복
        while (std::getline(config_file, line)) {
            if (line.find("server {") != std::string::npos) {
                Server* server = new Server(config_file);
                servers.insert(server);
                std::vector<std::string> serverName = server->getServerName();
                for (std::vector<std::string>::iterator it = serverName.begin(); it != serverName.end(); it++) {
                    std::string ip = get_ip(serverName[0]);
                    std::string host = *it;
                    Listener::getInstance().addServer(ip, server->getPort(), host, server);
                }
            }
        }
        config_file.close();

        std::cout << "Server initialized!" << std::endl;
        Listener::getInstance().listen_server();
        std::cout << "Server listening!" << std::endl;

        while (true)
        {
            try
            {
                std::cout << "in mainloop!" << std::endl;
                IOServer::getInstance().mainLoop();
                std::cout << "out mainloop!" << std::endl;
            }
            catch (const std::exception& e) 
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
            
        }
        
    

        std::cout << "hello world" << std::endl;
    }

    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    // 서버 리스트;
    // 

    



    // 서버는 생성되면서, listener에게 호스트를 등록 (lister는 싱글톤으로 만든다.)
        // listener는 등록된 호스트로 소켓을 연다.
        // 소켓이 들어오면 리스너는 '연결'인스턴스를 만들어 서버가 초기화할수 있도록 넘긴다.
        // 연결 인스턴스는 리스너의 맵에 저장된다. 리스너는 연결이 끊어지면, 연결 맵에서 인스턴스를 지운다.
        // 연결 인스턴스는, http요청을 받으며 요청 인스턴스를 만든다. 요청 인스턴스는 요청을 처리하고 응답한다.
        // 
    // 









   
    return 0;
}
