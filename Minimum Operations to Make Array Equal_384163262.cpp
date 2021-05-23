class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        int A[n];
        for (int i = 0; i < n; ++i) A[i] = (2 * i) + 1;
        for (int i = 0; i < ceil(n / 2); ++i) ans += (A[n - i - 1] - A[i]) / 2;        
        return ans;
    }
};
