class Solution {
public:
    
    int maxFreq = 1;
    string ans = "";
    
    struct Trie{
        bool end;
        string pref;
        unordered_map<char, int> freq;        
        unordered_map<char, Trie*> M;
        
        Trie() {
            end = false;            
        }
    };
    
    void insert(Trie *root, string s) {
        for (int j = 0; j < s.length(); ++j) {
            char i = s[j];
            if (root->M.find(i) == root->M.end()) {
                root->M[i] = new Trie();
            } 
            root->freq[i] += 1;            
            root->pref = s.substr(0, j + 1);
            if (maxFreq <= root->freq[i]) {
                maxFreq = root->freq[i];
                ans = root->pref;
            }
            root = root->M[i];
        }
        root->end = true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        Trie *root = new Trie();
        for (string s : strs) insert(root, s);
        return maxFreq != strs.size() ? "" : ans;
    }
};
