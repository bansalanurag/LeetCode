class Solution {
public:
    
    bool isSubset(vector<int> &nums, int target) {
        int n = nums.size();
        int m = target;
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1));
        for (int i = 0; i <= n; ++i) dp[i][0] = true;
        for (int i = 1; i <= m; ++i) dp[0][i] = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }    
            }
        }
        return dp[n][m];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) sum += i;
        
        if (sum & 1)
            return false;
        else
            return isSubset(nums, sum / 2);
    }
};
