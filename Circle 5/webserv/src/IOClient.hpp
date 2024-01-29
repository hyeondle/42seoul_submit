#ifndef IOCLIENT_HPP
#define IOCLIENT_HPP

#include <sys/types.h>
#include <sys/event.h>
#include <string>


class IOClient {
public:
    virtual ~IOClient() {}
    
    //kevent event handlr
    //virtual void handleKevent(uintptr_t fd, std::string type) = 0;
    virtual void handleKevent(uintptr_t fd, std::string type, struct kevent * event) = 0;

    //message event handlr
    virtual void handleMessage(uintptr_t fd, std::string type) = 0;

    struct kevent * self_event;

};

#endif // IOCLIENT_H
