class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int a, b, c, d;
        int s = 0;
        a = b = 0;
        c = INT_MIN;
        d = INT_MAX;
        
        for (int i : A) {
            a = (a + i > i) ? a + i : i; 
            c = max(c, a);
            
            b = (b + i < i) ? b + i : i;
            d = min(d, b);
            
            s += i;
        }
        
        if (s == d) return c;
        return max(s - d, c);
    }
};
