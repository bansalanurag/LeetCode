class Solution {
public:
    
    map<string, vector<string>> M;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (M.find(s) != M.end())
            return M[s];
        
        vector<string> result;
        if (s.empty()) {
            result.push_back("");
            return result;
        }
        
        for (string word : wordDict) {
            int len = word.length();
            if (s.substr(0, len) == word) {
                vector<string> subResult = wordBreak(s.substr(len), wordDict);
                for (string sub : subResult) {
                    string space = sub.empty() ? "" : " ";                    
                    result.push_back(word + space + sub);
                }
            }
        }
        
        M[s] = result;
        return result;
    }
};
