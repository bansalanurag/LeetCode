class Solution {
public:
    double myPow(double x, long n) {
        double res = 1;
        bool neg = false;
        if (n < 0) {neg = true; n *= -1; }
        while (n) {
            if (n&1) res *= x;
            x *= x;
            n >>= 1;
        }
        return (neg ? 1 / res : res);
    }
};
