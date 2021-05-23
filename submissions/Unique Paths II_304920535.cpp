class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        bool a;
        int n = A.size();
        int m = A[0].size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long> (m, 0));
        
        a = false;
        for (int i = 0; i < m; ++i) {
            if (!a) {
                if (A[0][i] == 1) {
                    a = true;
                    dp[0][i] = 0;
                } else 
                    dp[0][i] = 1;                  
            }
            else { 
                A[0][i] = 1;                
                dp[0][i] = 0;     
            }
        }
        a = false;
        for (int i = 0; i < n; ++i) {
            if (!a) {
                if (A[i][0] == 1) {
                    a = true;
                    dp[i][0] = 0;
                } else 
                    dp[i][0] = 1;                  
            }
            else { 
                A[i][0] = 1;                
                dp[i][0] = 0;     
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (A[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else dp[i][j] = 0;
            }
        }
        return dp[n - 1][m - 1];
    }
};
