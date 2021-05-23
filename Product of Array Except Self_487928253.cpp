class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        
        for (int i = 0; i < n; ++i) {
            left[i] = i == 0 ? nums[i] : nums[i] * left[i - 1];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            right[i] = (i == n - 1) ? nums[i] : nums[i] * right[i + 1];
        }
                
        vector<int> prod(n);        
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                prod[i] = right[i + 1];
            } else if (i == n - 1) {
                prod[i] = left[i - 1];
            } else
                prod[i] = left[i - 1] * right[i + 1];
        }
        
        return prod;
    }
};
