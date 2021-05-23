class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {        
        if (envelopes.empty())
            return 0;
        
        sort(envelopes.begin(), envelopes.end(), [] (const vector<int> a, const vector<int> b) {
            if (a[0] < b[0])
                return true;
            else if (a[0] == b[0])
                return a[1] < b[1];
            return false;
        });
        
        int ans = 1;
        int n = envelopes.size();        
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for (int i = 1; i < n; ++i) {
            int a = 0;
            for (int j = 0; j <= i; ++j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    a = max(dp[j], a);
            }
            dp[i] = a + 1;
            ans = max(ans, dp[i]);
        }
                      
        return ans;
    }
};

/*
int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;        
        int ans = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            int a = 0;
            for (int j = 0; j <= i; ++j) {
                if (nums[j] < nums[i])
                    a = max(a, dp[j]);
            }
            
            dp[i] = 1 + a;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
    */
