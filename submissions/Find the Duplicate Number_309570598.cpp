class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> A;
        for (auto i : nums) {
            if (A.find(i) != A.end()) return i;
            else A.insert(i);
        }
        return -1;
    }
};
