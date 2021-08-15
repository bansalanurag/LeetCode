typedef struct TrieNode {
    int sum;    
    unordered_map<char, TrieNode*> child;
    
    TrieNode() : sum(0) {}    
} TrieNode;

class Trie {
public:
    TrieNode *root; 
    unordered_map<string, int> dict;
    
    Trie() {
        root = new TrieNode();
    }
    
    int insert(string s, int val) {
        TrieNode *traverse = this->root;
        bool alreadyPresent = dict.find(s) != dict.end();
        
        for (char c : s) {
            if (traverse->child.find(c) == traverse->child.end()) {
                traverse->child[c] = new TrieNode();         
            }
            traverse = traverse->child[c];
            traverse->sum = alreadyPresent ? (traverse->sum - dict[s] + val) : (traverse->sum + val); 
        }   
        
        dict[s] = val;
        return traverse->sum;
    }
    
    int search(string s) {
        TrieNode *traverse = this->root;        
        for (char c : s) {
            if (traverse->child.find(c) == traverse->child.end())
                return 0;            
            traverse = traverse->child[c];
        }
        
        return traverse->sum;
    }
    
    ~Trie() {
        if (root != nullptr)
            delete root;
        root = nullptr;
    }
};

class MapSum {
public:
    
    Trie t;
    
    MapSum() {
    }
    
    void insert(string key, int val) {
        t.insert(key, val);
    }
    
    int sum(string prefix) {
        return t.search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */