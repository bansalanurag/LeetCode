class Solution {
public:
    
    int countSubsetWhichSumToTarget(vector<int> &A, int target) {
        int n = A.size();
        int dp[n + 1][target + 1];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] += dp[i-1][0];
            if (A[i-1] == 0)              
                dp[i][0] *= 2;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) { 
                dp[i][j] = dp[i - 1][j];
                if (j >= A[i - 1])
                    dp[i][j] += dp[i - 1][j - A[i - 1]];                    
            }
        }
        
        return dp[n][target];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i : nums) sum += i;
        
        if (S > sum || S < -sum || S + sum < 0 || (S + sum) % 2 == 1) {
            return 0;
        }
                
        int target = (S + sum) / 2;  
        return countSubsetWhichSumToTarget(nums, target);
    }
};
