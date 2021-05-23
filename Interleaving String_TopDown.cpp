class Solution {
public:
    
    map<pair<string, string>, bool> dp;
    
    bool isInterleave(string s1, string s2, string s3) {
        // Recursive + memoization
        
        if (s1.length() + s2.length() != s3.length())
            return false;
        
        if (s1.empty() && s2.empty() && s3.empty())
            return true;
        
        pair<string, string> p = {s1, s2};
        if (dp.find(p) != dp.end())
            return dp[p];
        
        dp[p] = false;
        if (s1[0] == s3[0] && s2[0] == s3[0]) {            
            dp[p] = isInterleave(s1.substr(1), s2, s3.substr(1)) || isInterleave(s1, s2.substr(1), s3.substr(1));
        } else if (s1[0] == s3[0]) {
            dp[p] = isInterleave(s1.substr(1), s2, s3.substr(1));
        } else if (s2[0] == s3[0]) {
            dp[p] = isInterleave(s1, s2.substr(1), s3.substr(1));
        }
        
        return dp[p];
    }
};
