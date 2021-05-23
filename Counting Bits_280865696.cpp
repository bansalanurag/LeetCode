class Solution {
public:
    int countB(int n) {
        int count = 0;
        while(n) {
            if (n&1) count += 1;
            n >>= 1;
        }
        return count;
    }
    
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; ++i) 
            ans[i] = countB(i);
        return ans;
    }
};
