#include "Connection.hpp"
#include <unistd.h>
#include <sys/socket.h>
#include <cstring>
#include "Listener.hpp"
#include "Utils.hpp"

# define FL(i, n) for(int i=0; i < n; i++)

Connection::Connection(int socket, Server* server, sockaddr_in client_addr)
    : socket_fd(socket), default_server(server), client_addr(client_addr){
        IOServer::getInstance().subscribe_ever(socket, "read", this);
        //IOServer::getInstance().subscribe_ever(socket, "write", this);
        will_shutdown = false;
        // parsingRequest = 0;
        //activeRequests.clear();
        //active_request_count = 0;
}

Connection::~Connection() {
    delete_connection();
}

//void Connection::handleKevent(uintptr_t fd, std::string type)
void Connection::handleKevent(uintptr_t fd, std::string type, struct kevent * event){
    this->self_event = event;
    {std::cout << "Connection handleKevent callbacked --fd:" << fd << " --type: " << type << std::endl;}
    
    {std::cout << "Connection handleKevent callbacked event :"<< this->self_event <<" --data:" << this->self_event->data << std::endl;}

    if (type == "read") { processConnection();}
    else if (type == "write") {sendResponse();}
    else {     } //TODO? or blank?
    (void) fd;
}

void Connection::handleMessage(uintptr_t uintptr_request, std::string message) {
    Request* request = reinterpret_cast<Request*>(uintptr_request);
    std::cout << "Connection : handleMessage called : " << message << std::endl;
    if (message == "delete_request") {
        delete_request(request);
        return;
    }
    if (message == "shutdown_connection") {
        shutdown_connection();
        return;
    }
    if (message == "reprocess_connection") {
        processConnection();
        return;
    }
    std::cout << "after shutdown" << std::endl;
    std::cerr << "Cannot Process Message. Received: Connection, Message: " << message << std::endl;
}

void Connection::shutdown_connection() {
    {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() - will shutdown" <<std::endl;}
    if(!will_shutdown)
    {
        will_shutdown = true;
        IOServer::getInstance().cancle_subscribe(this->socket_fd, "read", this);
    }
    check_shutdown();
}

//
void Connection::shell_it_shutdown(){
    {std::cout << "connection "<< this <<" ::" <<"shell_it_shutdown() - will shutdown" <<std::endl;}
    //이후에 new 상태값과 타이머 도입해서 개선
    if (!will_shutdown && activeRequests.empty() && outqueue.empty() && this->buffer.size() < 3) shutdown_connection();
}


void Connection::processConnection() {
    mini_process_connection();
}

// void Connection::processConnection() {
//     char buffer[1024];
//     ssize_t bytes_read = recv(socket_fd, buffer, sizeof(buffer), 0); // 논블로킹 모드로 읽기

//     if (bytes_read > 0) {
//         // 버퍼에 데이터 추가
//         this->buffer.append(buffer, bytes_read);
//         int i = 1;
//         // 완전한 요청 검사
//         size_t end_of_request = this->buffer.find("\r\n\r\n");
//         while (end_of_request != std::string::npos) {

//             std::cout << "loop " << i << std::endl;
//             // 요청 분리
//             std::string request_str = this->buffer.substr(0, end_of_request + 4);
//             this->buffer.erase(0, end_of_request + 4);

//             // Request 객체 생성 및 처리
//             Request* newRequest = makeRequest(request_str);
//             activeRequests.insert(newRequest);
//             newRequest->processRequest();
//             std::cout << "back to connection loop" << std::endl;

//             // 다음 완전한 요청 검사
//             end_of_request = this->buffer.find("\r\n\r\n");
//             i++;
//         }
//             std::cout << "loop ou"<< std::endl;
//     } else if (bytes_read == 0) {
//         // 클라이언트가 연결을 종료함
//         shutdown_connection();
//     } else {
//         // 읽기 에러 처리
//         // 예: 로그 남기기, 오류 응답 전송 등
//     }
// }



// void Connection::processConnection() {
//    // std::cout << "connection "<< this <<" ::" <<"processConnection() called"<< std::endl;            
//     const size_t buffer_size = 8 * 1024 * 1024;

//     read_again:
//     char mini_buffer[buffer_size];
//     ssize_t bytes_read = recv(socket_fd, mini_buffer, sizeof(mini_buffer), 0); // 논블로킹 모드로 읽기

//     //std::cout << "connection "<< this <<" ::" <<"processConnection() recved"<< std::endl;            

//     if (bytes_read == buffer_size) {
//         this->buffer.append(mini_buffer, bytes_read);
//         goto read_again;
//     } else if (bytes_read > 0) {
//         // 버퍼에 데이터 추가
//         //std::cout << "Before append buffer"<< std::endl;            
        
//         this->buffer.append(mini_buffer, bytes_read);
//         //int i = 1;
//         // 완전한 요청 검사
//         //std::cout << "Before extract reques"<< std::endl;            

//         std::string request_str = find_complete_http_request(this->buffer);

//         //완전한 요청이 분리됨
//         if (10 < request_str.size()) {
//             //std::cout << "make new request with"<< request_str << std::endl;            
//             Request* newRequest = makeRequest(request_str, 0);
//             //std::cout << "back to connection loop" << std::endl;            
//         }
//     } 
//     else if (bytes_read == 0) {
//         // 클라이언트가 연결을 종료함
//         shutdown_connection();
//     } else {
//         // 읽기 에러 처리
//         // 예: 로그 남기기, 오류 응답 전송 등
//     }
// }



// void Connection::processConnection() {
//     버퍼
//     헤더버퍼
//     바디버퍼

//     1. 입력을 받아 버퍼에 채운다. 최대 3회까지.

//     2. 처리한다.
//         만약 헤더버퍼가 비어 있다면:
//             버퍼에서 해더를 찾는다, 찼았다면: 
//                 헤더부분을 헤더버퍼에 집어넣는다.
//                 contents_length를 확인한다. 만약 maxsize를 넘으면 예외처리한다.
//             찾지 못했다면:
//                 리턴한다.
//         만약 헤더버퍼가 차 있다면
//             헤더를 보고 본문이 chunked encode 되어 있는지 확인한다. 만약 안 되어 있다면.:
//                 길이 카운터가 찰 때까지 본문을 읽어 본문에다가 집어넣는다.
//                 만약 길이카운터가 찼다면: 요청을 완성해서 제공한다.
//                 안 찼다면 : 리턴한다.
//             만약 chunked endcode 되어 있다면
//                 길이카운터가 0인지 먼저 확인한다.
//                     0이라면, 맨 처음 한줄이 있다면 확인해 길이카운터 값에 넣는다.
//                     0이 아니라면 여기2로 점프한다.
//                 만약 길이카운터에 0이 들어가 있으면, 요청을 완성해서 제공한다.
//                 여기2:
//                 만약 0이 아니라면 버퍼의 길이가 길이카운터보다 긴지 확안한다.
//                     길이카운터가 0이 될때까지 내용을 본문에 넣는다.
                
// }



/*

"""
    1. 입력을 받아 버퍼에 채운다. 최대 3회까지.

    2. 처리한다.
        만약 헤더버퍼가 비어 있다면:
            버퍼에서 해더를 찾는다, 찼았다면: 
                헤더부분을 헤더버퍼에 집어넣는다.
                contents_length를 확인한다. 만약 maxsize를 넘으면 예외처리한다.
            찾지 못했다면:
                리턴한다.
        만약 헤더버퍼가 차 있다면
            헤더를 보고 본문이 chunked encode 되어 있는지 확인한다. 만약 안 되어 있다면.:
                길이 카운터가 찰 때까지 본문을 읽어 본문에다가 집어넣는다.
                만약 길이카운터가 찼다면: 요청을 완성해서 제공한다.
                안 찼다면 : 리턴한다.
            만약 chunked endcode 되어 있다면
                길이카운터가 0인지 먼저 확인한다.
                    0이라면, 맨 처음 한줄이 있다면 확인해 길이카운터 값에 넣는다.
                    0이 아니라면 여기2로 점프한다.
                만약 길이카운터에 0이 들어가 있으면, 요청을 완성해서 제공한다.
                여기2:
                만약 0이 아니라면 버퍼의 길이가 길이카운터보다 긴지 확안한다.
                    길이카운터가 0이 될때까지 내용을 본문에 넣는다.
   """             
*/


void Connection::read_data_to_buffer(){

    size_t leftdata = this->self_event->data;
    const size_t buffer_size = 8 * 1024;
    //int counter = 100;
    char mini_buffer[buffer_size];

    //최대 counter 번 읽는다.
    //while(counter--)
    {std::cout << "connection "<< this <<" ::" <<"read_data_to_buffer() leftsize = "<<leftdata <<std::endl;}
    
    if (0 < leftdata) {
        while(0 < leftdata)
        {
            ssize_t bytes_read = recv(socket_fd, mini_buffer, std::min(buffer_size, leftdata), 0); // 논블로킹 모드로 읽기
            {std::cout << "connection "<< this <<" ::" <<"read_data_to_buffer() bytes_read = "<<bytes_read <<std::endl;}

            if ( bytes_read > 0) //무언가 읽혔을 때
            {
                this->buffer.append(mini_buffer, bytes_read);//버퍼에 데이터 추가
                leftdata -= bytes_read;
            } else if (bytes_read == 0)//클라이언트가 연결을 종료
            {
                shutdown_connection();
                break;
            } else {// -1같은게 들어온 경우
                break;
            }
            
        }
    }
    else {
        shutdown_connection();
    }

}

static void print_mini_stat(Connection * thiss, std::string name)
{
    //디버깅 할떄 주석처리/.
    return;

    {std::cout << ""  << std::endl;}
    {std::cout << "print_mini_stat ::::" << name << std::endl;}
    {std::cout << "" << std::endl;}

    if (thiss->parsingMap.find("body") != thiss->parsingMap.end()) {
        std::cout << "connection "<< thiss <<" ::" <<"mini_process_connection() parsingMap[body] size ==" <<  thiss->parsingMap["body"].size() << std::endl;
    }

    {std::cout << "connection "<< thiss <<" ::" <<"mini_process_connection() transfered_body bytes ==" <<  thiss->parsingIntMap["transfered_body"] << std::endl;}
    {std::cout << "connection "<< thiss <<" ::" <<"mini_process_connection() leftbody body bytes   ==" <<  thiss->parsingIntMap["leftbody"] << std::endl;}
    {std::cout << "connection "<< thiss <<" ::" <<"mini_process_connection() buffer size           ==" <<  thiss->buffer.size() << std::endl;}
    {std::cout << "connection "<< thiss <<" ::" <<"mini_process_connection() now buffer = " << (thiss->buffer.substr(0,100)) <<std::endl;}
    if (10 < thiss->buffer.size()) {
        std::cout << "buffer =[";
        FL(i, 10) {std::cout <<int(thiss->buffer[i])<<", ";}
        std::cout << "]" << std::endl;
    }
    {std::cout << "" << std::endl;}

}

int Connection::find_and_get_header()
{
    {std::cout << "connection "<< this <<" ::" <<"find_and_get_header() start" <<std::endl;}

    size_t request_end = this->buffer.find("\r\n\r\n");

    // 요청의 끝을 찾지 못한 경우 빈 문자열 반환
    if (request_end == std::string::npos) {
        {std::cout << "connection "<< this <<" ::" <<"find_and_get_header() cannot find header end in buffer" <<std::endl;}
        return -1;
    }

    // 헤더와 본문을 분리
    parsingMap["header"] = buffer.substr(0, request_end);
    this->buffer.erase(0, request_end + 4);

    //content-Length 확인 -> parsingIntMap["Content-Length"]를 초기화, 정의 안 되어있으면 0;
    parsingIntMap["Content-Length"] = 0;
    size_t length_pos = parsingMap["header"].find("Content-Length: ");
    if (length_pos != std::string::npos) {
        length_pos += 16;
        size_t length_end = parsingMap["header"].find("\r\n", length_pos);
        int content_length = std::atoi(parsingMap["header"].substr(length_pos, length_end - length_pos).c_str());
        parsingIntMap["Content-Length"] = content_length;
    }

    //만약 chunked 인코딩 되어 있다면
    parsingIntMap["Chunked"] = 0;
    if (parsingMap["header"].find("Transfer-Encoding: chunked") != std::string::npos)
    {
        parsingIntMap["Chunked"] = 1;
    }

    {
        std::istringstream requestStream(parsingMap["header"]);
        std::string line;
        std::getline(requestStream, line);
        while (line.size() < 3) std::getline(requestStream, line);

        std::istringstream lineStream(line);
        lineStream >> parsingMap["method"] >> parsingMap["uri"] >> parsingMap["protocolVersion"];

    }

    {std::cout << "connection "<< this <<" ::" <<"find_and_get_header() header : " << parsingMap["header"] <<std::endl;}
    {std::cout << "connection "<< this <<" ::" <<"find_and_get_header() header parsed, will return" <<std::endl;}
    
    return 0;
}

void Connection::clear_parsing_maps()
{
    {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() map cleared" <<std::endl;}
    parsingIntMap.clear();
    parsingMap.clear();
    parsingRequest = 0;
}

void Connection::mini_process_connection(){
    {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() start" <<std::endl;}

    {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() read buffer" <<std::endl;}

    print_mini_stat(this, "<<<here>>> read header makebody buffering fill_left");

    read_data_to_buffer();

    print_mini_stat(this, "read <<<here>>> header makebody buffering fill_left");


    //주의 : 만약 에러 나면 이 부분 꺼보기
    //만약 처리할 데이터가 없으면 리턴
    if (this->buffer.empty()) {
        {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() buffer empty : will return" <<std::endl;}
        return;
    }

    if (parsingMap.find("header") == parsingMap.end())//헤더가 파싱되지 않은 경우
    {
        {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() header not paseed" <<std::endl;}

        //헤더를 가져다 맵[헤더] 에다 넣고, 사용할 맵인트 등을 초기화
        if(find_and_get_header())
        {
            {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() header cannot paseed:: return" <<std::endl;}
            return;//만약 헤더가 안 들어왔다면 리턴
        }
        {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() header paseed" <<std::endl;}
        
    }

    print_mini_stat(this, "read header <<<here>>> makebody buffering fill_left");
    
    if (parsingMap.find("body") == parsingMap.end())//바디 부분이 만들어지지 않은 경우.
    {
        {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() body not maked" <<std::endl;}
        // 요청에 body가 없는 경우.
        if (parsingIntMap["Content-Length"] == 0 && parsingIntMap["Chunked"] == 0)
        {
            //요청을 생성
            //parsingRequest = 
            makeRequest("" + parsingMap["header"] , 0);
            
            //if (parsingRequest) {parsingRequest->addQueue("\0");}
            {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() call bodyisend()" <<std::endl;}
            // parsingRequest->bodyisend();


            //다음 요청을 파싱할 준비하고 리턴
            clear_parsing_maps();
            return;
        }

        //헤더 파싱 수 만약 더 처리할 데이터가 없으면 리턴
        if (this->buffer.empty()) return;

        //헤더만 가지고 request 를 미리 생성
        // parsingRequest = makeRequest("" + parsingMap["header"] , 0);

        // body가 있는 경우 body 부분을 생성
        parsingMap["body"] = "";

        //parsingIntMap["leftbody"] 초기화
        parsingIntMap["leftbody"] = parsingIntMap["Content-Length"];

        // chunked body의 길이 체크를 위한 parsingIntMap["transfered_body"] 초기화 
        parsingIntMap["transfered_body"] = 0;

        {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() body initialized" <<std::endl;}
    }



    transfering_start:

    print_mini_stat(this, "read header makebody <<<here>>> buffering fill_left");


    // 버퍼에서 옮겨 담아야 하는 부분이 남은 경우.
    if (parsingIntMap["leftbody"] > 0)
    {
        {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() read leftbody" << std::endl;}

        // 이번에 옮길 양은, leftbody와 buffer의 남은 양 중 작은 값
        size_t transfer_byte = std::min(this->buffer.size(), static_cast<size_t>(parsingIntMap["leftbody"]));
        {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() transfer_byte="<<transfer_byte << std::endl;}

        //만약 옮길 자료가 있다면
        if (0 < transfer_byte)
        {
            //버퍼의 데이터를 해당 량만큼 옮기고
            try 
            {
                print_mini_stat(this, "read header makebody buffering{ <<<here>>> append others } fill_left");

                //parsingMap["body"].append(this->buffer, transfer_byte);
                std::string new_string = this->buffer.substr(0, transfer_byte);
                //{std::cout << "connection "<< this <<" ::" <<"mini_process_connection() new_string="<<new_string << std::endl;}
                parsingMap["body"] += new_string;
                //if(parsingRequest) parsingRequest->addQueue("" + new_string);
            }
            catch (std::exception &e) {
                {std::cout << "connection "<< this <<" ::" <<" cannot append body : will returned and recalled" << std::endl;}
                IOServer::getInstance().deliverEvent(1, "reprocess_connection", this); return;
            }
                print_mini_stat(this, "read header makebody buffering{ append <<<here>>>  others } fill_left");
            this->buffer.erase(0, transfer_byte);
            parsingIntMap["transfered_body"] += transfer_byte;
            parsingIntMap["leftbody"] -= transfer_byte;
                print_mini_stat(this, "read header makebody buffering{ append others <<<here>>>} fill_left");

        }
        // //없다면 리턴
        // else return;
        
        //만약 옮겨담던 도중에 그 길이를 넘어선 것을 체크한다면
        if (default_server->uri2maxsize(parsingMap["uri"]) < 0ul + parsingIntMap["transfered_body"] + parsingIntMap["leftbody"])
        {
            //오류를 반환하고, 연결을 종료한다.
            //if (parsingRequest) {parsingRequest->stopAndReturnError(413); return;}

            makeRequest(parsingMap["header"], 413);
            shutdown_connection(); return;
        }
    
    }
    print_mini_stat(this, "read header makebody buffering <<<here>>> fill_left");

    // 만약에 버퍼에서 읽어올 만큼 다 읽었다면
    if (parsingIntMap["leftbody"] == 0) 
    {
        {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() leftbody ==" << parsingIntMap["leftbody"] << std::endl;}

        //만약 chunked 라면
        if (parsingIntMap["Chunked"])
        {
            //새로 값을 읽어다가 leftbody 에 넣기
            //if (this->buffer.size() < 2)  return; //다음 입력을 기다림
            if (this->buffer.size() < 5)  return; //다음 입력을 기다림
            
            print_mini_stat(this, "read header makebody buffering fill_left{<<<here>>> erase2 }");

            size_t chunk_size_end = this->buffer.find("\r\n");
            if (chunk_size_end == 0) 
            {
                this->buffer.erase(0, 2); //남은 여백을 처리함            
                chunk_size_end = this->buffer.find("\r\n");
            }
            
            // 청크 끝을 찾을 수 없는 경우
            if (chunk_size_end == std::string::npos) return; //다음 입력을 기다림

            //if (chunk_size_end == 0) this->buffer.erase(0, 2); //남은 여백을 처리함
            //if (this->buffer[0] == '\r')

            print_mini_stat(this, "read header makebody buffering fill_left{ erase2 <<<here>>> }");

            // 만약 버퍼의 길이가 4보다 작다면 (청크사이즈가 0인 경우 예외처리를 위해)



            // 청크 크기 파싱
            std::string chunk_size_str = buffer.substr(0, chunk_size_end);
            this->buffer.erase(0, chunk_size_end + 2);
            {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() chunk_size_str = " << chunk_size_str.substr(0,100) << std::endl;}
            
            std::stringstream ss(chunk_size_str);
            int chunk_size;
            ss >> std::hex >> chunk_size;
            //int chunk_size = std::stoi(chunk_size_str, nullptr, 16);

            {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() chunk_size = " << chunk_size << std::endl;}

            // 마지막 청크에 도달
            if (chunk_size == 0) {
                //\r\n\r\n을 버퍼에서 정리하고, 요청을 생성.
                this->buffer.erase(0, chunk_size_end + 4);

                // //만약 헤더를 가지고 요청을 미리 만든 경우에 이렇게 처리한다.
                // if (parsingRequest) {
                //     {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() call bodyisend()" <<std::endl;}
                //     parsingRequest->bodyisend();
                //     //parsingRequest->addQueue("\0");
                //     clear_parsing_maps();
                //     return;
                // }

                makeRequest("" + parsingMap["header"] + "\r\n\r\n" + parsingMap["body"], 0);

                //다음 요청을 파싱할 준비하고 리턴
                clear_parsing_maps();
                return;
            }
            //읽을 수 있는 청크가 더 남은경우
            else if (0 < chunk_size)
            {
                parsingIntMap["leftbody"] = chunk_size;
                {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() chunk_size = " << chunk_size << " and goto transfering_start" << std::endl;}
                goto transfering_start;
            }
            //여긴 -가 들어온 경우
            else {}

        }
        //chunked 가 아니라면
        else
        {   
            //\r\n\r\n을 버퍼에서 정리하고, 요청을 생성.
            this->buffer.erase(0, 4);

            // //만약 헤더를 가지고 요청을 미리 만든 경우에 이렇게 처리한다.
            // if (parsingRequest) {
            //     {std::cout << "connection "<< this <<" ::" <<"mini_process_connection() call bodyisend()" <<std::endl;}
            //     parsingRequest->bodyisend();
            //     // parsingRequest->addQueue("\0");
            //     clear_parsing_maps();
            //     return;
            // }

            makeRequest("" + parsingMap["header"] + "\r\n\r\n" + parsingMap["body"], 0);

            //다음 요청을 파싱할 준비하고 리턴
            clear_parsing_maps();
            return;
        }


    }


}







// // HTTP 요청을 분석하고 완전한 요청을 찾아내는 함수
// // input: 분석할 전체 문자열 (참조로 전달되어 함수 내에서 수정됨)
// // max_content_length: 허용되는 최대 Content-Length 값
// std::string Connection::find_complete_http_request(std::string& input) {
//     // HTTP 헤더의 끝을 찾음
//     size_t request_end = input.find("\r\n\r\n");

//     // 요청의 끝을 찾지 못한 경우 빈 문자열 반환
//     if (request_end == std::string::npos) {
//         return "";
//     }

//     // 헤더와 본문을 분리
//     std::string headers = input.substr(0, request_end);
//     std::string body = input.substr(request_end + 4);

//     // Content-Length 헤더를 찾고 확인
//     size_t length_pos = headers.find("Content-Length: ");
//     if (length_pos != std::string::npos) {
//         length_pos += 16;
//         size_t length_end = headers.find("\r\n", length_pos);
//         int content_length = std::atoi(headers.substr(length_pos, length_end - length_pos).c_str());

//         // Content-Length가 설정된 최대 길이를 초과하는 경우 예외 발생
//         if (content_length > default_server->getclientBodysize()) {
//             makeRequest(headers, 413);
//             //instant_response(413, "Payload Too Large");
//             shutdown_connection(); return "";
//         }

//         // 본문 길이가 Content-Length보다 작은 경우 빈 문자열 반환
//         if (body.length() < static_cast<size_t>(content_length)) {
//             return "";
//         } else {
//             // 완전한 요청을 반환하고 입력 문자열에서 제거
//             std::string complete_request = input.substr(0, request_end + 4 + content_length);
//             input.erase(0, request_end + 4 + content_length);
//             return complete_request;
//         }
//     }

//     if (headers.find("Transfer-Encoding: chunked") != std::string::npos) {
//         {std::cout << "process chunked : start with body :"<< body << std::endl;}
//         std::string unchunked_body;
//         size_t chunk_start = 0;

//         while (chunk_start < body.size()) {
//             size_t chunk_end = body.find("\r\n", chunk_start);
//             if (chunk_end == std::string::npos) {
//                 // 청크 끝을 찾을 수 없음
//                 {std::cout << "cannot find chunk end: " << unchunked_body << std::endl;}
//                 break;
//             }
            
//             // 청크 크기 파싱
//             std::string chunk_size_str = body.substr(chunk_start, chunk_end - chunk_start);
//             int chunk_size = std::stoi(chunk_size_str, nullptr, 16);

//             if (chunk_size == 0) {
//                 // 마지막 청크에 도달
//                 break;
//             }

//             // 청크 데이터 추출
//             size_t chunk_data_start = chunk_end + 2; // "\r\n" 다음부터 시작
//             unchunked_body.append(body, chunk_data_start, chunk_size);
//             {std::cout << "checking unchunking : " << unchunked_body << std::endl;}

//             // 다음 청크로 이동
//             chunk_start = chunk_data_start + chunk_size + 2; // 청크 데이터와 "\r\n"을 건너뛰기
            
//             //만약 지정된 크기를 초과하면 중단하고 오류를 리턴하는 응답을 생성;
//             if (unchunked_body.length() > default_server->getclientBodysize()) {
//                 makeRequest(headers, 413);
//                 //instant_response(413, "Payload Too Large");
//                 shutdown_connection(); return "";
//             }
//         }

//         // Chunked 데이터를 일반 텍스트로 변환
//         body = unchunked_body;
//     }

//     // // Chunked Transfer-Encoding 처리
//     // if (headers.find("Transfer-Encoding: chunked") != std::string::npos) {
//     //     size_t chunked_end = body.find("0\r\n\r\n");
//     //     if (chunked_end == std::string::npos) {
//     //         return "";
//     //     } else {
//     //         // 완전한 요청을 반환하고 입력 문자열에서 제거
//     //         std::string complete_request = input.substr(0, request_end + 4 + chunked_end + 5);
//     //         input.erase(0, request_end + 4 + chunked_end + 5);
//     //         return complete_request;
//     //     }
//     // }

//     // 헤더만 있는 경우, 헤더를 반환하고 입력 문자열에서 제거
//     input.erase(0, request_end + 4);
//     return headers + "\r\n\r\n" + body;
// }



// void Connection::processConnection() {
//     char buffer[1024];
//     ssize_t bytes_read;
//     bool isChunked = false;
//     int contentLength = -1;
//     int MAX_CONTENT_LENGTH = this->default_server->getclientBodysize(); // 최대 허용 길이 설정

//     std::cout << "before connection loop" << std::endl;
//     int i = 1;
//     while ((bytes_read = recv(socket_fd, buffer, sizeof(buffer), 0)) > 0) {
//         std::cout << "loop : " << i << std::endl;
//         std::cout << "bytes_read : " << bytes_read << std::endl;
//         this->buffer.append(buffer, bytes_read);

//         if (contentLength < 0) {
//             // Content-Length 또는 Transfer-Encoding 확인
//             size_t header_end = this->buffer.find("\r\n\r\n");
//             if (header_end != std::string::npos) {
//                 std::string header = this->buffer.substr(0, header_end);
//                 size_t contentLengthPos = header.find("Content-Length: ");
//                 size_t chunkedPos = header.find("Transfer-Encoding: chunked");
//                 if (contentLengthPos != std::string::npos) {
//                     sscanf(header.c_str() + contentLengthPos + 16, "%d", &contentLength);
//                 }
//                 isChunked = chunkedPos != std::string::npos;
//             }
//             std::cout << "contentLength : " << contentLength << std::endl;
//             std::cout << "isChunked : " << isChunked << std::endl;
//             // std::cout << "header : " << header << std::endl;
//         }

//         // Content-Length에 따른 처리
//         if (contentLength >= 0) {
//             if (contentLength > MAX_CONTENT_LENGTH) {
//                 this->shutdown_connection();
//                 return;
//             }
//             if (this->buffer.size() >= contentLength + 4) { // 헤더 길이 포함
//                 // 요청 처리
//                 processRequestWithLength(contentLength);
//                 // 버퍼에서 요청 제거
//                 this->buffer.erase(0, contentLength + 4);
//                 contentLength = -1;
//             }
//         } else if (isChunked) {
//             // Chunked 처리
//             processChunkedRequest();
//         } else {
//             // Content-Length가 없는 경우
//             if (this->buffer.size() > MAX_CONTENT_LENGTH) {
//                 this->shutdown_connection();
//                 return;
//             }
//         }
//     }
//     std::cout << "after connection loop" << std::endl;
//     if (bytes_read == 0) {
//         // 클라이언트 연결 종료
//         shutdown_connection();
//     } else {
//         // 오류 처리
//     }
// }



Request* Connection::makeRequest(std::string str, int code) {
    Request* request = new Request(-1, this);
    {std::cout << "Connector.makeRequest : new Request = "<< request << std::endl;}
    {std::cout << "connection "<< this <<" ::" <<"makeRequest() requst_str.size = " << str.size() << std::endl;}    
    request->initialize(str, code);
    {std::cout << "Connector.makeRequest : Request initialized" << std::endl;}
    //activeRequests.insert(reinterpret_cast<uintptr_t>(request), request);
    activeRequests.insert(request);
    request->processRequest();
    //active_request_count++;

    return request;
}

void Connection::delete_request(Request* request) {
    {std::cout << "Connector.delete_request :erase Request "<< request <<" in "<< activeRequests.size() << std::endl;}
    std::set<Request *>::iterator it = activeRequests.find(request);

    {std::cout << "Connector.delete_request : "<< request << " " << *(activeRequests.begin()) << "---" << std::endl;}


    if (it == activeRequests.end()) return;
    delete request;
    activeRequests.erase(it);
    {std::cout << "Connector.delete_request : now requests size =  "<< activeRequests.size() << std::endl;}
    //active_request_count--;
    IOServer::getInstance().cleanClient(request);
    //모든 요청이 처리되었을때, 자신이 종료되어야 하는지 체크
    check_shutdown();
}

void Connection::check_shutdown() {
    {std::cout << "Connection "<< socket_fd <<" check_shutdown callbacked --will shutdown:" << will_shutdown << " --requests: " << activeRequests.size() << " outqueue.size: " << outqueue.size()  << std::endl;}
    if (will_shutdown && activeRequests.empty() && outqueue.empty()) {
        IOServer::getInstance().deliverEvent(socket_fd, "delete_connection", &(Listener::getInstance()));
    }
}

void Connection::delete_connection() {
    for (std::set<Request*>::iterator it = activeRequests.begin(); it != activeRequests.end(); ++it) {
        delete *it;
    }
    activeRequests.clear();
    close(socket_fd);
    IOServer::getInstance().cleanClient(this);

    {std::cout << "Connection " << this << " closed" << std::endl;}
}


void Connection::sendResponse() {
    std::cout << "sendResponse called" << std::endl;
    {std::cout << "Connection::sendResponse() byteleft this->self_event->data = " << this->self_event->data << std::endl;}
    if (!outqueue.empty() && 0 < static_cast<size_t>(this->self_event->data) && !(this->self_event->fflags & EV_ERROR)) {
        if (outqueue.front().size() > 1000) {std::cout << outqueue.front().substr(0,100) << std::endl;}
        else {std::cout << outqueue.front() << std::endl;}
        std::string & response = outqueue.front();
        //ssize_t bytes_sent = send(socket_fd, response.c_str(), response.size(), MSG_DONTWAIT); // 비블로킹 쓰기
        int count = 1;
        while (count--)
        {
            // ssize_t bytes_will_sent = std::max(std::min(response.size(), 8ul * 1024 * 1024), (size_t)0);
            ssize_t bytes_will_sent = std::max(std::min(response.size(), static_cast<size_t>(this->self_event->data - 2)), (size_t)0);
            // ssize_t bytes_will_sent = response.size();
            //ssize_t bytes_sent = send(socket_fd, response.c_str(),   std::min((size_t)(8ull * 1024 * 1024), response.size()), MSG_DONTWAIT); // 비블로킹 쓰기
            // ssize_t bytes_sent = send(socket_fd, response.c_str(), bytes_will_sent, MSG_DONTWAIT); // 비블로킹 쓰기
            ssize_t bytes_sent = send(socket_fd, response.c_str(), bytes_will_sent, 0); // 비블로킹 쓰기
            //ssize_t bytes_sent = write(socket_fd, response.c_str(), bytes_will_sent); // 비블로킹 쓰기
            {std::cout << "Connection::sendResponse() byteleft with outqueue.first = " << outqueue.front().size() << std::endl;}
            {std::cout << "Connection::sendResponse() bytes_sent = " << bytes_sent << std::endl;}


            if (bytes_sent == -1) {
                // 쓰기 실패 처리, 예: EAGAIN/EWOULDBLOCK 에러 대응
                std::cout << "sendResponse send = -1" << std::endl;
                //usleep(100000);
                break;
            } else if (bytes_sent < static_cast<ssize_t>(response.size())) {
            // } else if (bytes_sent < bytes_will_sent) {
                // 쓰기가 완료되지 않은 경우, 남은 데이터를 추적
                outqueue.front() = response.erase(0, bytes_sent);
                // outqueue.front() = response.substr(bytes_sent);
                std::cout << "sendResponse send = "<< bytes_sent << " not done "<< std::endl;
            } else if (bytes_sent == static_cast<ssize_t>(response.size())) {
            // } else if (bytes_sent == bytes_will_sent) {
                // 쓰기가 완료된 경우, 큐에서 제거
                std::cout << "sendResponse send = "<< bytes_sent << " done" << std::endl;
                outqueue.pop();
                check_shutdown();
                break;
            } else {
                // 쓰기가 완료된 경우, 큐에서 제거
                std::cout << "sendResponse send = "<< bytes_sent << " done??" << std::endl;
                outqueue.pop();
                check_shutdown();
            }
        }
        
    }
    else if (static_cast<size_t>(this->self_event->data) == 0 || this->self_event->fflags & EV_ERROR)
    {
        {std::cout << "Connection::sendResponse() cannot send : socket closed , will shutdown connection" << outqueue.front().size() << std::endl;}
        IOServer::getInstance().cancle_subscribe(socket_fd, "write", this);
        this->shutdown_connection();
        
    }

    if (!outqueue.empty())
    {
        std::cout << "sendResponse queue not empty!" << std::endl;

        //IOServer::getInstance().subscribe(socket_fd, "write", this);
        
    }else{
        IOServer::getInstance().cancle_subscribe(socket_fd, "write", this);
    }

}


// void Connection::sendResponse() {
//     std::cout << "sendResponse called" << std::endl;
//     {std::cout << "Connection::sendResponse() this->self_event"<<this->self_event<<"->data = " << this->self_event->data << std::endl;}
//     if (!outqueue.empty() && 0 < static_cast<size_t>(this->self_event->data)) {
//     {std::cout << "Connection::sendResponse() outqueue.front().size() = " << outqueue.front().size() << std::endl;}

//         if (outqueue.front().size() > 1000) {std::cout << outqueue.front().substr(0,100) << std::endl;}
//         else {std::cout << outqueue.front() << std::endl;}
//         std::string & response = outqueue.front();
//         //ssize_t bytes_sent = send(socket_fd, response.c_str(), response.size(), MSG_DONTWAIT); // 비블로킹 쓰기
//         int count = 1;
//         while (count--)
//         {
//             // ssize_t bytes_will_sent = std::min(response.size(), static_cast<size_t>(this->self_event->data));
//             ssize_t bytes_will_sent = response.size();
//             //ssize_t bytes_sent = send(socket_fd, response.c_str(),   std::min((size_t)(8ull * 1024 * 1024), response.size()), MSG_DONTWAIT); // 비블로킹 쓰기
//             ssize_t bytes_sent = send(socket_fd, response.c_str(), bytes_will_sent, MSG_DONTWAIT); // 비블로킹 쓰기
//             {std::cout << "Connection::sendResponse() byteleft with outqueue.first = " << outqueue.front().size() << std::endl;}
//             {std::cout << "Connection::sendResponse() bytes_sent = " << bytes_sent << std::endl;}


//             if (bytes_sent == -1) {
//                 // 쓰기 실패 처리, 예: EAGAIN/EWOULDBLOCK 에러 대응
//                 std::cout << "sendResponse send = -1" << std::endl;
//                 //usleep(100000);
//                 break;
//             } else if (bytes_sent < static_cast<ssize_t>(response.size())) {
//             // } else if (bytes_sent < bytes_will_sent) {
//                 // 쓰기가 완료되지 않은 경우, 남은 데이터를 추적
//                 outqueue.front() = response.erase(0, bytes_sent);
//                 // outqueue.front() = response.substr(bytes_sent);
//                 std::cout << "sendResponse send = "<< bytes_sent << " not done "<< std::endl;
//             } else if (bytes_sent == static_cast<ssize_t>(response.size())) {
//             // } else if (bytes_sent == bytes_will_sent) {
//                 // 쓰기가 완료된 경우, 큐에서 제거
//                 std::cout << "sendResponse send = "<< bytes_sent << " done" << std::endl;
//                 outqueue.pop();
//                 check_shutdown();
//                 break;
//             } else {
//                 // 쓰기가 완료된 경우, 큐에서 제거
//                 std::cout << "sendResponse send = "<< bytes_sent << " done??" << std::endl;
//                 outqueue.pop();
//                 check_shutdown();
//             }
//         }
        
//     }
//     else if (static_cast<size_t>(this->self_event->data) == 0)
//     {
//         {std::cout << "Connection::sendResponse() cannot send : socket closed , will shutdown connection" << outqueue.front().size() << std::endl;}

//         this->shutdown_connection();
//     }

//     if (!outqueue.empty())
//     {
//         std::cout << "sendResponse queue not empty!" << std::endl;

//         IOServer::getInstance().subscribe(socket_fd, "write", this);
//     }
// }

void Connection::addOutQueue(std::string response) {
    
    if (this->outqueue.empty()) IOServer::getInstance().subscribe_ever(socket_fd, "write", this);

    size_t cutsize =  1024 * 1024 * 1024;
    // size_t cutsize =  64 * 1024;

    while (cutsize < response.size())
    {
        outqueue.push(response.substr(0, cutsize));
        response.erase(0, cutsize);    
    }
    outqueue.push(response);

}


std::string Connection::client_host()
{
    return address_to_string(this->client_addr);
}


Server * Connection::get_default_server()
{
    return this->default_server;
}


void Connection::instant_response(int num, std::string message)
{
    std::string content = this->default_server->defaultErrorPage(num);
    std::stringstream ss;

    ss << "HTTP/1.1 " << num << " " <<  message << "\r\n\r\n"
    << "Content-Length:" << content.length() << "\r\n"
    << "Content-Type: text/plain" << "\r\n"
    << "\r\n"
    << content
    << "\r\n\r\n";
    addOutQueue(ss.str());
}

