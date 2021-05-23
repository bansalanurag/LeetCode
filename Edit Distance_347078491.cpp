class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.length();
        if (word2.empty()) return word1.length();
        
        int n = word1.length();
        int m = word2.length();
        int dp[n + 1][m + 1];
        
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) dp[i][0] = 1 + dp[i - 1][0];        
        for(int i = 1; i <= m; i++) dp[0][i] = 1 + dp[0][i - 1];        
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {                                 
                    dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : 1 + min({dp[i - 1][j], dp[i][j - 
                        1], dp[i - 1][j - 1]});
            }
        }
        return dp[n][m];
    }
};
