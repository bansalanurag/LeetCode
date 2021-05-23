class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int currMin = 1, currMax = 1;
        for (int i : nums) {
            int temp = currMin * i;
            currMin = min({currMin * i, currMax * i, i});            
            currMax = max({currMax * i, temp, i});
            
            ans = max(ans, currMax);
        }
        
        return ans;
    }
};

// int ans = INT_MIN;
//         int currMin = 1, currMax = 1;
//         for (int i : nums) {
//             int temp = currMin * i;
//             currMin = min({currMin * i, currMax * i, i});
//             currMax = max({currMax * i, temp, i});
//              ans = max(ans, currMax);
//         }
        
//         return ans;
