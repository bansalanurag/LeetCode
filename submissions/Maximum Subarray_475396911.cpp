class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0, maxNeg = INT_MIN;
        bool allNeg = true;
        for (int i : nums) {
            maxNeg = max(maxNeg, i);
            if (i >= 0) {
                allNeg = false;
                break;
            }
        }
        
        if (allNeg)
            return maxNeg;
        
        
        int curr = 0;
        for (int i : nums) {
            curr += i;
            if (curr < 0)
                curr = 0;
            if (ans < curr)
                ans = curr;
        }
        
        return ans;
    }
};
