#ifndef SERVER_HPP
#define SERVER_HPP

#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>

#include "Trie.hpp"

class Server {
public:
    Server(std::ifstream& config_file);
    ~Server();

    void configure(const std::string& configPath);
    void parse(std::ifstream& file);
    void parse_server(std::vector<std::string>& tokens);
    void parse_location(std::ifstream& file, std::streampos& position);
    void parse_cgi(std::ifstream& file, std::streampos& position);
    void serveRequest();

    //uri를 받고 longest 매칭된 location 을 찾아, 처리해야 하는 파일의 주소를 제공함
        //디렉터리 기본파일이 존재하는 경우, 기본파일을 리턴함
    //
    std::string uri2path(std::string uri);                            // uri 를 받아서 지칭하는 파일으 path를 반환
    std::string uri2CGIPath(std::string uri);                         // uri를 받아서 CGI 처리해야 하는 경우 CGI 스크립트의 경로를 반환, CGI 처리가 필요 없는 경우 "-isnotCGI" 반환
    bool        uricanMethod(std::string uri, std::string method);    // uri 와 "GET" | "POST" 같은 걸 넣으면 사용할 수 있는지 반환함
    std::string uri2uploadLocation(std::string uri);                  // uri 를 받아서 업로드 할 경로를 리턴, 만약 upload 불가능하면 "-cannotUpload" 반환
    std::string uri2index(std::string uri);
    //bool        isUriWriteable(std::string uri);
    //std::pair<int, std::string> uri2redirection(std::string uri);
    std::string uri2redirection(std::string uri);                     // 리디렉션될 주소 반환, 만약 리디렉션이 아닌 경우 "-isnotRedirection" 반환 <주의 : http 같은거 안 붙어 나옴>
    bool uri2directoryListing(std::string uri);                             // 해당 uri가 디렉토리 리스팅 되어야 하는지 반환

    size_t uri2maxsize(std::string uri);


    std::string errorPagePath(int num);
    std::string defaultErrorPage(int num);

    

    size_t getclientBodysize();

    void printALL();
    std::vector<std::string> getServerName() const;
    int getPort() const;
    std::string getMimeType(const std::string& filePath);

    std::string code2status(int code);

    
private:
    //std::string server_ip;
    std::vector<std::string> serverName;
    int port;
    std::map<int, std::string> errorPages;
    size_t clientMaxBodySize;

    std::map<std::string, std::set<std::string> > allowedMethodsPerLocation;
    std::map<std::string, std::string> redirections;
    std::map<std::string, bool> directoryListing;
    std::map<std::string, std::string> defaultFiles;
    std::map<std::string, std::string> uploadPaths;
    std::map<std::string, std::string> cgiPerLocation;
    std::map<std::string, std::string> cgiPerExtension;
    std::map<std::string, std::string> aliases;

    std::map<std::string, size_t> clientMaxBodySizes;

    std::map<std::string, std::string> mimetypes;
    void initMimeTypes();

    std::map<int, std::string> codeAndStatus;
    void init_code2status();


    //Trie tri;
    Trie tri_allowedMethodsPerLocation;
    Trie tri_redirections;
    Trie tri_directoryListing;
    Trie tri_defaultFiles;
    Trie tri_uploadPaths;
    Trie tri_cgiPerLocation;
    Trie tri_cgiPerExtension;
    Trie tri_aliases;
    Trie tri_maxsize;

    std::string extractExtension(const std::string& );
    // More configuration as needed...
};

#endif // SERVER_HPP

