class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        int ans = 0;
        int n = A.size();
        if (n == 0) return ans;
        
        int m = A[0].size();
        
        vector<vector<int>> dp (n, vector<int> (m, 0));
        
        for (int i = 0; i < n; ++i) { dp[i][0] = A[i][0] - '0'; ans = max(ans, dp[i][0]); }
        for (int i = 0; i < m; ++i) { dp[0][i] = A[0][i] - '0'; ans = max(ans, dp[0][i]); }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (A[i][j] == '1') {
                    if (A[i - 1][j] == A[i][j - 1] && A[i - 1][j - 1] == A[i - 1][j] && A[i - 1][j] == '1') {
                        if (dp[i - 1][j] == dp[i][j - 1] && dp[i - 1][j - 1] == dp[i - 1][j])
                            dp[i][j] = dp[i - 1][j - 1] + 1;                      
                        else
                            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    } else {
                        dp[i][j] = 1;
                    }
                    ans = max(ans, dp[i][j]);
                }        
            }
        }
        
        return (ans * ans);
    }
};
