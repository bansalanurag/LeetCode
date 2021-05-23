class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;        
        
        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                len = min(len, right - left + 1);
                sum -= nums[left++];
            }
            right += 1;
        }
        
        return len == INT_MAX ? 0 : len;
    }
};
