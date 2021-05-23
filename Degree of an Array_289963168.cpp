class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int d = 0, ans = INT_MAX;
        vector<int> C(50000, 0);
        vector<int> S(50000, -1), E(50000, -1);
        for (int i = 0; i < nums.size(); ++i) { 
            C[nums[i]] += 1;
            S[nums[i]] == -1 ? S[nums[i]] = E[nums[i]] = i : E[nums[i]] = i;
            if (d < C[nums[i]]) d = C[nums[i]];            
        }        
        for (int i = 0; i < C.size(); ++i) if (C[i] == d) ans = min(ans, E[i] - S[i] + 1);
        return ans;
    }
};
