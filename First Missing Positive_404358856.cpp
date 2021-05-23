class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int count = 1;
        set<int> A;
        for (int i : nums) A.insert(i);
        for (int i : A) {
            if (i <= 0) continue;
            if (i == count) 
                count += 1;
            else
                break;
        }
        return count;
    }
};
