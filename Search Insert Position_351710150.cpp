class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
