class Trie {
public:
    struct TrieNode{
        bool end;
        unordered_map<char, TrieNode*> M;
    };    
    TrieNode *root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
        root->end = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); ++i) {
            if (temp->M.find(word[i]) == temp->M.end()) 
                temp->M[word[i]] = new TrieNode();
            temp = temp->M[word[i]];
        }
        temp->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); ++i) {
            if (temp->M.find(word[i]) == temp->M.end()) 
                return false;
            temp = temp->M[word[i]];
        }
        return temp->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (temp->M.find(prefix[i]) == temp->M.end()) 
                return false;
            temp = temp->M[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
