class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN || x == INT_MAX)   return 0;
        bool neg;
        long rem = 0;        
        x < 0 ? neg = true : neg = false;
        x = abs(x);
        while (x) {
            if (rem * 10 > INT_MAX) {
                rem = 0;
                break;
            }
            rem = (rem * 10) + (x % 10);
            x /= 10;
        }
        return (rem ? neg ? rem * (-1) : rem : 0);
    }
};
