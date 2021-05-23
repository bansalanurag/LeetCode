class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Fast IO
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int ans = 0;
        
        // Corner Case.
        if (matrix.size() == 1) {
            for (int i : matrix[0]) if (i) ans += 1;
            return ans;
        }
        
        // Intializers.
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        // Base Case.
        for (int i = 0; i < n; ++i) {
            if (matrix[i][0]) {
                ans += 1;
                dp[i][0] = 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[0][i]) {
                if (i != 0) ans += 1;
                dp[0][i] = 1;
            }
        }
                
        // Filling DP table.
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 1) {
                    if (matrix[i - 1][j] == matrix[i][j - 1] && matrix[i][j - 1] == matrix[i - 1][j - 1] && 
                        matrix[i - 1][j - 1] == 1) {
                        if (dp[i - 1][j] == dp[i][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1]) {
                            dp[i][j] = dp[i - 1][j - 1] + 1;                            
                        } else {
                            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                        }
                        ans += dp[i][j];
                    }
                    else {
                        dp[i][j] = 1;
                        ans += 1;
                    }
                }
            }
        }
            
        return ans;
    }
};
