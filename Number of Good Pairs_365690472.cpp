class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> M;
        for (int i = 0; i < nums.size(); ++i) {
            if (M.find(nums[i]) != M.end()) 
                ans += M[nums[i]];
            M[nums[i]] += 1;
        }
        return ans;
    }
};
