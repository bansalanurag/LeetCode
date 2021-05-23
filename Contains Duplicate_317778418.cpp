class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> S;
        for (auto i : nums) {
            if (S.find(i) != S.end()) return true;
            S.insert(i);
        }
        return false;
    }
};
