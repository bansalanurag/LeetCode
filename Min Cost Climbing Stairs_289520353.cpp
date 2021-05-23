class Solution {
public:
    int solve(vector<int> &cost, vector<int> &dp, int n) {
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        dp[n] = min(solve(cost, dp, n - 1), solve(cost, dp, n - 2)) + cost[n];
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 0) return 0;
        cost.push_back(0);
        int n = cost.size();
        vector<int> dp(n, -1);
        return solve(cost, dp, n - 1);
    }
};
