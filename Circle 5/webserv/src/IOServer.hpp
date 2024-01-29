#ifndef IOSERVER_HPP
#define IOSERVER_HPP

#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iostream>

#include "IOClient.hpp"


struct Task {
    uintptr_t  fd;
    IOClient* client;
    std::string type;
    short filter; // 이벤트 필터 (EVFILT_READ, EVFILT_WRITE 등)
    u_short flags; // 액션 플래그 (EV_ADD, EV_ENABLE 등)

    Task(uintptr_t fd, IOClient* client, std::string type, short filter, u_short flags)
        : fd(fd), client(client), type(type), filter(filter), flags(flags) {}
};

class IOServer {
private:
    std::queue<Task> taskQueue; // 파일 입출력 작업 큐
    std::queue<Task> queue2; // 이벤트 전달 작업 큐
    //std::map<int, std::pair<void*, size_t>> workingMap; // 실행중인 작업 맵

    struct kevent* changeList; // kevent 입력용 배열
    struct kevent* eventList;  // kevent 출력용 배열
    int changeListSize;
    int eventListSize;
    int kq;

    std::set<IOClient*> cleanSet;


    IOServer();
    IOServer(int changeListSize, int eventListSize);
    ~IOServer();

public:
    static IOServer & getInstance();
    void subscribe(uintptr_t fd, std::string type, IOClient* client);
    void subscribe_ever(uintptr_t fd, std::string type, IOClient* client);
    void cancle_subscribe(uintptr_t  fd, std::string type, IOClient* client);

    //해당 pid가 종료된 경우 알림.
    void subscribe_processdie(uintptr_t  pid, IOClient* client);

    void deliverEvent(uintptr_t contents, std::string type, IOClient* client);
    void mainLoop();

    void cleanClient(IOClient * client);

};

#endif