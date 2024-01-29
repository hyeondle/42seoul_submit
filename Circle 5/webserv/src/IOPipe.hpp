#ifndef IOPIPE_HPP
#define IOPIPE_HPP


#include "IOClient.hpp"
#include <sys/types.h>
#include <string>
#include <map>

class IOPipe : public IOClient {
private:
    static std::map<std::pair<int, int>, IOPipe > pipes

    std::string pipe(int read_fd, int write_fd)

    IOPipe(int read_fd, int write_fd)
    {
        
    }
public:

    static IOPipe * getInstance(int read_fd, int write_fd)
    {

    }    



    std::string buffer;


    ~IOPipe();
    
    //kevent event handlr
    void handleKevent(uintptr_t fd, std::string type)
    {

    }

    //message event handlr
    void handleMessage(uintptr_t fd, std::string type);

};

#endif // IOWRAPPER_HPP
