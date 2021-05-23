class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> compliments;
        for (int i = 0; i < nums.size(); ++i) {
            if (compliments.find(target - nums[i]) != compliments.end()) {
                ans.push_back(compliments[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            
            compliments[nums[i]] = i;
        }
        
        return ans;
    }
};
