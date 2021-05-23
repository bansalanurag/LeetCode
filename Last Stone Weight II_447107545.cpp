class Solution {
public:
    
    int subsetSumMinDiff(vector<int> &A, int sum) {
        int n = A.size();
        bool dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < sum + 1; ++j) {
                if (i == 0) 
                    dp[i][j] = false;                
                if (j == 0)
                    dp[i][j] = true;
                if (i > 0 && j > 0) {                    
                    if (A[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];                    
                    else
                        dp[i][j] = dp[i - 1][j];                    
                }
            }
        }
        
        int ans= INT_MAX;
        for (int i = 0; i <= sum / 2; ++i) {
            ans = min(ans, dp[n][i] ? sum - (2 * i) : INT_MAX);
        }
        
        return ans;
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        if (stones.size() == 1)
            return stones[stones.size() -1];
        int sum = 0;
        for (int i : stones) sum += i;
        return subsetSumMinDiff(stones, sum);        
    }
};
