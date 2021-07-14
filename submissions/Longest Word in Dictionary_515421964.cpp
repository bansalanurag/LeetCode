class Solution {
public:
    
    string ans = "";
    
    typedef struct TrieNode {
        bool end;
        unordered_map<char, TrieNode*> child;        
        TrieNode() { this->end = false; }        
    } Trie;
    
    Trie* getNode() {
        Trie *root = new Trie();
        return root;
    }
    
    void insertIntoTrie(string& word, Trie* root) {
        for (char c : word) {
            if (root->child.find(c) == root->child.end()) {
                root->child[c] = getNode();
            }
            root = root->child[c];
        }
        root->end = true;
    }
    
    void traverseTrie(Trie* root, string current) {        
        if (root->end) {
            if (current.length() > ans.length())
                ans = current;
            else if (current.length() == ans.length())
                ans = min(ans, current);
        }        
        
        for (auto e : root->child) {
            if (e.second->end) {
                traverseTrie(e.second, current + e.first);
            }
        }
    }
    
    string longestWord(vector<string>& words) {
        if (words.empty())
            return "";
        
        Trie *root = getNode();
        for (string word : words) {
            insertIntoTrie(word, root);
        }
        
        traverseTrie(root, "");
        return ans;    
    }
};