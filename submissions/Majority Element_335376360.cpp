class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        int ans = 0;
        unordered_map<int, int> M;
        for (int i : nums) {
            M[i] += 1;
            if (M[i] > floor(nums.size() / 2)) ans = i;
        }
        return ans;
    }
};
