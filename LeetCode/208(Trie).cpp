class Trie {
private:
    vector<Trie*> son;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->son[ch] == nullptr) return nullptr;
            node = node->son[ch];
        }
        return node;
    }

public:
    Trie() : son(26), isEnd(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->son[ch] == nullptr) {
                node->son[ch] = new Trie();
            }
            node = node->son[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};