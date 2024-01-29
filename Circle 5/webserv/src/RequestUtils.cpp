#include "RequestUtils.hpp"
#include "Request3.hpp"

// std::string uriToFilepath(const std::string& uri) {
	
// 	std::string base_directory = "/" + server->uri2path(uri);; // 경로 웹 서버 루트로
// 	return base_directory + uri;
// }


// 해당 메소드 IOServer에서 이벤트로 처리하도록 수정하기
bool readFileContents(const std::string& filepath, std::vector<char>& buffer) {
	std::ifstream file(filepath.c_str(), std::ios::binary | std::ios::ate); // 여는 것 자체는 논블록
	if (!file) return false;

	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	buffer.resize(size);
	if (file.read(&buffer[0], size)){ // 읽기에서 블록
		file.close();
		return true;
	} else {
		file.close();
		return false;
	} 
}

// temp
// bool readFileContents(const std::string& filepath, std::vector<char>& buffer) {
// 	std::ifstream file(filepath.c_str(), std::ios::binary | std::ios::ate);
// 	if (!file) return false;

// 	std::streamsize size = file.tellg();
// 	file.seekg(0, std::ios::beg);

// 	buffer.resize(size);
// 	if (file.read(&buffer[0], size)) return true;
// 	else return false;
// }

//기본 block모드이므로, non-block 모드로 소켓 설정하거나 kqueue로 논블록 맞는지 체크 필요
bool receivePostData(int client_socket, std::string& data) {
    char buffer[1024]; //버퍼 사이즈 설정하기 임시로 1024로 함
    int received = 0;
    while ((received = recv(client_socket, buffer, 1023, 0)) > 0) {
        buffer[received] = '\0';
        data += buffer;
    }
    return received >= 0;
}