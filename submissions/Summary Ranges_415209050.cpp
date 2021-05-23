class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans;
        
        int start, end;
        start = end = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                end = i;
            } else {
                if (start !=  end) 
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                else
                    ans.push_back(to_string(nums[start]));
                start = end = i;
            }
        }
        if (start !=  end) 
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        else
            ans.push_back(to_string(nums[start]));
        return ans;
    }
};
