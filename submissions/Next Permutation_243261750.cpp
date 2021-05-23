class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        for(; k > 0; --k) {
            if(nums[k - 1] < nums[k])
                break;
        }
        if(k == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        auto it = upper_bound(nums.rbegin(), nums.rend() - k, nums[k - 1]);
        swap(nums[k - 1], *it);
        reverse(nums.begin() + k , nums.end());
    }
};
