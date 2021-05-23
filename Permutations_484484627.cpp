class Solution {
public:
    
    void permutation(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int l, int r) {
        if (l > r) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = l; i <= r; ++i) {
            curr.push_back(nums[i]);
            swap(nums[i], nums[l]);
            permutation(ans, curr, nums, l + 1, r);
            curr.pop_back();
            swap(nums[i], nums[l]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        permutation(ans, curr, nums, 0, nums.size() - 1);
        return ans;
    }
};
