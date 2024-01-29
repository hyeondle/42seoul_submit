// #include <fstream>
// #include <sstream>
// #include <string>
// #include <vector>

// // Multipart 요청 파싱을 위한 간단한 클래스
// class MultipartParser {
// public:
//     MultipartParser(const std::string& boundary) : boundary("--" + boundary) {}

//     void parse(const std::string& body) {
//         std::istringstream stream(body);
//         std::string line;
//         while (std::getline(stream, line)) {
//             if (line == boundary || line == boundary + "--") {
//                 if (!currentName.empty()) {
//                     files[currentName] = currentData;
//                 }
//                 currentName.clear();
//                 currentData.clear();
//             } else if (line.find("Content-Disposition:") == 0) {
//                 size_t namePos = line.find("name=\"");
//                 if (namePos != std::string::npos) {
//                     namePos += 6; // "name=\"" 길이
//                     size_t nameEndPos = line.find("\"", namePos);
//                     currentName = line.substr(namePos, nameEndPos - namePos);
//                 }
//             } else if (!line.empty() && line[0] != '\r') {
//                 currentData += line + "\n";
//             }
//         }
//     }

//     const std::map<std::string, std::string>& getFiles() const {
//         return files;
//     }

// private:
//     std::string boundary;
//     std::string currentName;
//     std::string currentData;
//     std::map<std::string, std::string> files;
// };

// // 파일 저장 함수
// bool saveFile(const std::string& filename, const std::string& data) {
//     std::ofstream file(filename, std::ios::binary);
//     if (!file.is_open()) {
//         return false;
//     }
//     file.write(data.c_str(), data.size());
//     return true;
// }

// // 예제 사용
// int main() {
//     std::string requestBody = /* HTTP 요청 본문 */;
//     std::string boundary = /* Boundary 값 */;

//     MultipartParser parser(boundary);
//     parser.parse(requestBody);

//     const auto& files = parser.getFiles();
//     for (const auto& file : files) {
//         std::string filename = "/path/to/save/" + file.first;
//         saveFile(filename, file.second);
//     }

//     return 0;
// }


// ///////////////////////////////////////
// ///////////////////////////////////////
// ///////////////////////////////////////


// #include <fstream>
// #include <string>

// // 파일 저장 함수
// bool saveFile(const std::string& filename, const std::string& data) {
//     std::ofstream file(filename, std::ios::binary);
//     if (!file.is_open()) {
//         return false;
//     }
//     file.write(data.c_str(), data.size());
//     return true;
// }

// // 파일 업로드 처리 함수
// void handleFileUpload(const std::string& requestHeaders, const std::string& requestBody) {
//     // Content-Type 검사 (예: "image/png")
//     std::string expectedContentType = "image/png"; // 예상 파일 타입
//     if (requestHeaders.find("Content-Type: " + expectedContentType) == std::string::npos) {
//         // 잘못된 파일 타입 처리
//         return;
//     }

//     // 파일 저장
//     std::string filename = "/path/to/save/uploaded_file.png";
//     if (!saveFile(filename, requestBody)) {
//         // 파일 저장 실패 처리
//     }
// }

// int main() {
//     std::string requestHeaders = /* HTTP 요청 헤더 */;
//     std::string requestBody = /* HTTP 요청 본문 (파일 데이터) */;

//     handleFileUpload(requestHeaders, requestBody);

//     return 0;
// }
