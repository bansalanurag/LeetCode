class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int ans = 0;
        for (int i : nums) ans ^= i;
        return ans;
    }
};
