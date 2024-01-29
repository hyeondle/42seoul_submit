#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <set>

// struct TrieNode {
//     // std::map<std::string, TrieNode*> children;
//     bool isEndOfPath;
    

//     // TrieNode() : isEndOfPath(false) {}
//     // ~TrieNode() {
//     //     // for (std::map<std::string, TrieNode*>::iterator it = children.begin(); it != children.end(); ++it) {
//     //     //     delete it->second;
//     //     // }
//     // }
// };

class Trie {
public:
    Trie();
    ~Trie();
    // void insert(const std::string& path);
    // std::string findLongestMatchingPath(const std::string& uri);

    void insert(const std::string& str);
    std::string findLongestMatchingPath(const std::string& query);

    // void collectPaths(TrieNode* node, const std::string& path, std::vector<std::string>& paths);
    void printAllPaths();
    
private:
    // TrieNode* root;
    std::map<int, std::set<std::string> > lengthMap;
};


/*
int main() {
    Trie trie;

    trie.insert("/abc/def");
    trie.insert("/abc");
    trie.insert("/");

    std::string longestMatch = trie.findLongestMatchingPath("/abc/def/g/");
    std::cout << "Longest Match: " << longestMatch << std::endl;

    return 0;
}
*/

#endif // TRIE_HPP