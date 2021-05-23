class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty())
            return false;
        
        unordered_map<string, bool> visited;
        queue<string> Q;
        for (string word : wordDict) {
            if (word == s.substr(0, word.length())) {
                Q.push(word);
                visited[word] = true;
            }
        }
        
        
        while (!Q.empty()) {
            string curr = Q.front(); Q.pop();
            
            if (curr == s) {
                return true;
            }
            
            for (string word : wordDict) {
                string next = curr + word;
                if (visited.find(next) == visited.end()) {
                    if (s.substr(0, next.length()) == next) {
                        Q.push(next);
                        visited[next] = true;
                    }
                }
            }
        }
        
        return false;
    }
};
