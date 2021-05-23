class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        int ans = 0;
        unordered_set<char> S;
        for (int i = 0, j = 0; j < (int) s.length(); j++) {
            while (j < s.length() && S.find(s[j]) == S.end()) {
                S.insert(s[j]);                
                j += 1;
            }
            
            ans = max(ans, j - i);
            while (i <= j && S.find(s[j]) != S.end()) {
                S.erase(s[i]);
                i += 1;
            }
            S.insert(s[j]);
            ans = max(ans, j - i);            
        }
        
        return ans;
    }
};
