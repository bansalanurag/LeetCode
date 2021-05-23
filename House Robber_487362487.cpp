class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = max(nums[i - 1], nums[i] + ((i - 2) >= 0 ? nums[i - 2] : 0));
        }
              
        return nums[nums.size() - 1];
    }
};

/*


        
*/
