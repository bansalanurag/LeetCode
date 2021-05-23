class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> M;
        M.insert({0, -1});
        int maxlen = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count = count + (nums[i] == 1 ? 1 : -1);
            if (M.find(count) != M.end()) {
                maxlen = max(maxlen, i - M[count]);
            } else {
                M.insert({count, i});
            }
        }
        return maxlen;
    }
};
