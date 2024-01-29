#include "Trie.hpp"



// Trie::Trie() : root(new TrieNode()) {}
Trie::Trie() {}

// Trie::~Trie() {	delete root;}
Trie::~Trie() {}

// void Trie::insert(const std::string& path) {
// 	TrieNode* current = root;
// 	std::istringstream iss(path);
// 	std::string token;
// 	while (std::getline(iss, token, '/')) {
// 		if (token.empty()) continue;
// 		if (current->children.find(token) == current->children.end()) {
// 			current->children[token] = new TrieNode();
// 		}
// 		current = current->children[token];
// 	}
// 	current->isEndOfPath = true;
// }


// std::string Trie::findLongestMatchingPath(const std::string& uri) {
//     // if (uri == "/") {
//     //     return uri; // 루트 경로 반환
//     // }

// 	// // int count = 0;
//     // TrieNode* current = root;
//     // std::istringstream iss(uri);
//     // std::string token, longestMatch;
//     // while (std::getline(iss, token, '/')) {
//     //     if (token.empty()) continue;
//     //     if (current->children.find(token) == current->children.end()) {
//     //         break;
//     //     }
//     //     current = current->children[token];
        
// 	// 	//longestMatch += token + "/";
// 	// 	// if (count++) longestMatch += token + "/";
// 	// // 	if (count++) longestMatch.append("/" + token);
// 	// // 	else longestMatch += ("/" + token) ;
//     // //     {std::cout << "longest match = " << longestMatch << std::endl;}
//     // // }

//     // // if (current && current->isEndOfPath) {
//     // //     return (longestMatch);
//     // // }

//     // 	// if (count++) longestMatch += token + "/";
// 	// 	// else longestMatch += token;
//     //     longestMatch += "/" + token;
//     // }

//     // if (current && current->isEndOfPath) {
//     //     return longestMatch; // 이미 "/"로 시작하므로 추가적인 "/"는 필요하지 않음
//     // }

//     // return "/";
//      if (uri == "/") {
//         return uri; // 루트 경로 반환
//     }

//     TrieNode* current = root;
//     std::istringstream iss(uri);
//     std::string token, longestMatch;
//     bool isFirstToken = true;
//     while (std::getline(iss, token, '/')) {
//         // 첫 번째 토큰이 비어있는 경우(즉, uri가 "/"로 시작하는 경우) 무시
//         if (isFirstToken && token.empty()) {
//             isFirstToken = false;
//             continue;
//         }
//         if (current->children.find(token) == current->children.end()) {
//             break;
//         }
//         current = current->children[token];
//         longestMatch += "/" + token; // 여기서 슬래시를 추가
//         isFirstToken = false;
//     }

//     if (current && current->isEndOfPath) {
//         return longestMatch; // 이미 "/"로 시작하므로 추가적인 "/"는 필요하지 않음
//     }

//     return "/";
// }
// std::string Trie::findLongestMatchingPath(const std::string& uri) {
// 	TrieNode* current = root;
// 	std::istringstream iss(uri);
// 	std::string token, longestMatch;
// 	while (std::getline(iss, token, '/')) {
// 		if (token.empty()) continue;
// 		if (current->children.find(token) == current->children.end()) {
// 			break;
// 		}
// 		current = current->children[token];
// 		longestMatch += "/" + token;
// 	}

// 	if (current->isEndOfPath) {
// 		return longestMatch;
// 	}

// 	return "";
// }

void Trie::insert(const std::string& str) {
    lengthMap[str.length()].insert(str);
}

std::string Trie::findLongestMatchingPath(const std::string& query) {
    // 길이가 긴 문자열부터 역순으로 탐색
    for (std::map<int, std::set<std::string> >::reverse_iterator rit = lengthMap.rbegin(); rit != lengthMap.rend(); ++rit) {
        const std::set<std::string>& strings = rit->second;
        for (std::set<std::string>::const_iterator it = strings.begin(); it != strings.end(); ++it) {
            if (query.find(*it) != std::string::npos) {
                return *it;
            }
        }
    }
    return "";
}


// void Trie::collectPaths(TrieNode* node, const std::string& path, std::vector<std::string>& paths) {
//     if (node->isEndOfPath) {
//         paths.push_back(path);
//     }
//     for (std::map<std::string, TrieNode*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
//         collectPaths(it->second, path + "/" + it->first, paths);
//     }
// }

void Trie::printAllPaths() {
    for (std::map<int, std::set<std::string> >::iterator it = lengthMap.begin(); it != lengthMap.end(); ++it) {
        std::cout << "Length: " << it->first << std::endl;
        for (std::set<std::string>::iterator sit = it->second.begin(); sit != it->second.end(); ++sit) {
            std::cout << *sit << std::endl;
        }
    }
}