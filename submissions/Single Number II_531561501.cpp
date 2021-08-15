class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32];
        memset(cnt, 0, sizeof(cnt));
        
        for (int element : nums) {
            for (int i = 0; i < 32; ++i) {
                if (element & (1 << i))
                    cnt[i] += 1;
            }
        }
                        
        int ans = 0;
        for (int i = 0; i < 32; ++i) {                        
            if (cnt[i] > 0 && cnt[i] % 3 != 0) {
                ans |= (1 << i);
            }
        }
        
        return ans;
    }
};