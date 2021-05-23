class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) {
            return triangle[0][0];    
        }
        
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        int minTotal = INT_MAX;
        
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = (j == 0 ? dp[i - 1][j] : min(dp[i - 1][j], dp[i - 1][j - 1])) + triangle[i][j];
                if (i == n - 1)
                    minTotal = min(minTotal, dp[i][j]);     
            }            
        }
        
        return minTotal;
    }
};
