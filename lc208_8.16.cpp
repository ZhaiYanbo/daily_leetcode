//实现Trie(字典树)

class Trie {
private:
    vector<Trie*>child;
    bool isend;
    Trie* searchprefix(string word) {
        Trie* node = this;
        for(char ch:word) {
            if(node->child[ch-'a']==nullptr)
                return nullptr;
            node = node->child[ch-'a'];
        }
        return node;
    }
public:
    Trie() :child(26,nullptr),isend(false){}
    
    void insert(string word) {
        Trie* node = this;
        for(char ch:word)
        {
            if(node->child[ch-'a']==nullptr)
                node->child[ch-'a'] = new Trie();
            node = node->child[ch-'a'];
        }
        node->isend = true;
    }
    
    bool search(string word) {
        Trie* node = this->searchprefix(word);
        return node!=nullptr&&node->isend;
    }
    
    bool startsWith(string prefix) {
        return this->searchprefix(prefix)!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */