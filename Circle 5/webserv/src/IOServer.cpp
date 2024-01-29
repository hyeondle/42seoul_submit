#include "IOServer.hpp"
#include <unistd.h>
IOServer::IOServer():changeListSize(10000), eventListSize(10000) {
	changeList = new struct kevent[changeListSize];
	eventList = new struct kevent[eventListSize];
	kq = kqueue();
	if (kq == -1) {
		// 에러 처리
		throw std::runtime_error("IOServer::mainLoop() : Failed to create kqueue");
	}
};

IOServer::IOServer(int changeListSize, int eventListSize) : changeListSize(changeListSize), eventListSize(eventListSize) {
	changeList = new struct kevent[changeListSize];
	eventList = new struct kevent[eventListSize];
	kq = kqueue();
	if (kq == -1) {
		// 에러 처리
		throw std::runtime_error("IOServer::mainLoop() : Failed to create kqueue");
	}
}

IOServer::~IOServer() {
	delete[] changeList;
	delete[] eventList;
}

IOServer & IOServer::getInstance() {
	static IOServer s;
	return s;
}

// void IOServer::subscribe_processdie(int fd, std::string type, IOClient* client) {
// 	short filter; 
// 	if (type[0] == 'r') filter = EVFILT_READ;
// 	if (type[0] == 'w') filter = EVFILT_WRITE;
// 	taskQueue.push(Task(fd, client, type, filter, EV_ONESHOT | EV_ENABLE));
// }

void IOServer::subscribe_processdie(uintptr_t pid, IOClient* client) {
    // 프로세스 종료 이벤트를 감시하기 위한 설정
    short filter = EVFILT_PROC; 
    u_short flags = EV_ADD | EV_ONESHOT;
    
    taskQueue.push(Task(pid, client, "die", filter, flags));
}

void IOServer::subscribe(uintptr_t fd, std::string type, IOClient* client) {
	short filter; 
	if (type[0] == 'r') filter = EVFILT_READ;
	if (type[0] == 'w') filter = EVFILT_WRITE;
	// taskQueue.push(Task(fd, client, type, filter, EV_ONESHOT | EV_ENABLE));
	taskQueue.push(Task(fd, client, type, filter, EV_ONESHOT));
}

void IOServer::subscribe_ever(uintptr_t fd, std::string type, IOClient* client) {
	short filter; 
	if (type[0] == 'r') filter = EVFILT_READ;
	if (type[0] == 'w') filter = EVFILT_WRITE;
	taskQueue.push(Task(fd, client, type, filter, EV_ADD | EV_ENABLE));
}

void IOServer::cancle_subscribe(uintptr_t fd, std::string type, IOClient* client) {
	short filter; 
	if (type[0] == 'r') filter = EVFILT_READ;
	if (type[0] == 'w') filter = EVFILT_WRITE;
	taskQueue.push(Task(fd, client, type, filter, EV_DELETE | EV_DISABLE));
}

void IOServer::cleanClient(IOClient * client)
{
	this->cleanSet.insert(client);
}


void IOServer::deliverEvent(uintptr_t contents, std::string type, IOClient* client) {
	// 다른 객체로 이벤트 전달
	queue2.push(Task(contents, client, type, 0, 0));
}

void IOServer::mainLoop() {
	//int kq = this->kq; // kqueue 인스턴스 생성
	
	while (true) {
    	{std::cout << "IOServer mainLoop startpoint"  << std::endl;}
		
		// 1. 작업 정리: kevent에 등록할 작업을 taskQueue에서 가져오기
		int changeListCount = 0;
		while (!taskQueue.empty() && changeListCount < changeListSize) {
			Task task = taskQueue.front();
			taskQueue.pop();
			if (cleanSet.count(task.client)) continue;
			EV_SET(&changeList[changeListCount], task.fd, task.filter, task.flags, 0, 0, task.client);
			changeListCount++;
		}
    	
		{std::cout << "IOServer mainLoop changeListCount = "<< changeListCount  << std::endl;}

		cleanSet.clear();
		// 2. kevent 호출: 이벤트 대기 및 수신
		struct timespec timeout = {10, 0}; // 10초 타임아웃 설정
		int nev = kevent(kq, changeList, changeListCount, eventList, eventListSize, &timeout);
		if (nev < 0) {
			// 에러 처리
			throw std::runtime_error("IOServer::mainLoop() : kevent create error");
		}
		{std::cout << "IOServer mainLoop eventsize = "<< nev << std::endl;}

		// 3. 처리할 작업을 하나씩 호출
		for (int i = 0; i < nev; i++) {
			struct kevent event = eventList[i];
			IOClient* client = static_cast<IOClient*>(event.udata);
			if (client == 0 || cleanSet.count(client)) continue;

			
			// 이벤트 유형에 따른 처리
			if (event.filter == EVFILT_READ) {
				//client->handleKevent(event.ident, "read");
				client->handleKevent(event.ident, "read", &event);
			} else if (event.filter == EVFILT_WRITE) {
				//client->handleKevent(event.ident, "write");
				if (event.flags & EV_EOF) {
					std::cout << "Broken Pipe detected in fd" << event.ident << std::endl;
					cleanSet.insert(client);
					close(event.ident);
					continue;
				}
				client->handleKevent(event.ident, "write", &event);
			} else if (event.filter == EVFILT_PROC) {
				//client->handleKevent(event.ident, "die");
				client->handleKevent(event.ident, "die", &event);
			}
		}

		// queue2에서 추가 작업 처리 (필요한 경우)
		while (!queue2.empty())
		{
			/*
			queue2.front().client->handleMessage(queue2.front().fd, queue2.front().type);
			queue2.pop();
			*/
			/* code */
			Task& task = queue2.front();
			if (cleanSet.count(task.client)) continue;
			task.client->handleMessage(task.fd, task.type);
			queue2.pop();
		}
			
		// ...
	}
}
