#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* children[26]; 
    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
    int count; 

public:
    Trie() {
        root = new TrieNode();
        count = 0;
    }

    void insertSubstring(const string &s, int start) {
        TrieNode* node = root;
        for (int i = start; i < (int)s.size(); i++) {
            int idx = s[i] - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
                count++; 
            }
            node = node->children[idx];
        }
    }

    int getUniqueSubstringCount() const {
        return count;
    }
};

int countUniqueSubstrings(const string &s) {
    Trie trie;
    for (int i = 0; i < (int)s.size(); i++) {
        trie.insertSubstring(s, i);
    }
    return trie.getUniqueSubstringCount();
}

int main() {
    string s;
    cout << "Enter a lowercase string: ";
    cin >> s;

    for (char c : s) {
        if (c < 'a' || c > 'z') {
            cerr << "Error: Only lowercase letters allowed.\n";
            return 1;
        }
    }

    int result = countUniqueSubstrings(s);
    cout << "Number of unique substrings: " << result << "\n";

    return 0;
}
