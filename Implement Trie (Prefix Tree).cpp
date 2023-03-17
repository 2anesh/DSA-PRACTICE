class TrieNode {
    TrieNode* children[26] = {nullptr}; 
    bool isword; 
public: 
    ~TrieNode() {
        for (auto& child : children) 
            delete child; 
    }
friend class Trie; 
};


class Trie {
    TrieNode* root; 
public:
    Trie() {
        root = new TrieNode(); 
    }
    
    ~Trie() {
        delete root; 
    }
    
    void insert(string word) {
        TrieNode* node = root; 
        for (auto& ch : word) {
            if (!node->children[ch-'a']) node->children[ch-'a'] = new TrieNode(); 
            node = node->children[ch-'a']; 
        }
        node->isword = true; 
    }
    
    bool search(string word) {
        TrieNode* node = root; 
        for (auto& ch : word) {
            if (!node->children[ch-'a']) return false; 
            node = node->children[ch-'a']; 
        }
        return node->isword; 
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root; 
        for (auto& ch : prefix) {
            if (!node->children[ch-'a']) return false; 
            node = node->children[ch-'a']; 
        }
        return true; 
    }
};
