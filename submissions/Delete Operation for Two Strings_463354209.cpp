class Solution {
public:
    
    int LCS(string X, string Y) {
        if (!X.empty() && Y.empty() || X.empty() && !Y.empty())
            return 0;
        
        int n = X.length();
        int m = Y.length();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);                    
            }
        }
        
        return dp[n][m];
    }
    
    int minDistance(string word1, string word2) {
        int len = LCS(word1, word2);
        return (word1.length() - len) + (word2.length() - len);
    }
};