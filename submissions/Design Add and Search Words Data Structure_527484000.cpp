typedef struct Trie {
    bool end;
    unordered_map<char, Trie*> child;
    
    Trie() {
        end = false;
    }
    
} Trie;

class WordDictionary {
public:
    Trie *root = nullptr;
    
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *traverse = root;
        for (char c : word) {
            if (traverse->child.find(c) == traverse->child.end())
                traverse->child[c] = new Trie();
            traverse = traverse->child[c];
        }
        traverse->end = true;
    }
    
    bool dfs(Trie *traverse, int k, string &word) {
        if (k >= word.length()) {
            return traverse->end;
        }
        
        bool matching = false;
        for (auto i : traverse->child) {
            char c = i.first;
            if (c == word[k] || word[k] == '.') {
                matching = dfs(traverse->child[c], k + 1, word);
                if (matching)
                    break;
            }
        }
        
        return matching;
    }
    
    bool search(string word) {        
        return dfs(root, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */