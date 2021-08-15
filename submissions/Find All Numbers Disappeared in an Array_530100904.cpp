class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int cnt = 1;
        vector<int> ans;
        unordered_set<int> S;
        
        for (int i : nums) S.insert(i);
        while (cnt <= nums.size()) {
            if (S.find(cnt) == S.end())
                ans.push_back(cnt);
            cnt += 1;
        }
        
        return ans;
    }
};