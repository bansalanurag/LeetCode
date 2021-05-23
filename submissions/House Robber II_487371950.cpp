class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> dp(nums.size() - 1, 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size() - 1; ++i) {
            dp[i] = max(dp[i - 1], nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0));
        }
                
        for (int i = 2; i < nums.size(); ++i) {
            nums[i] = max(nums[i - 1], nums[i] + (i - 2 >= 1 ? nums[i - 2] : 0));
        }                
               
        return max(dp[dp.size() - 1], nums[nums.size() - 1]);
    }
};
