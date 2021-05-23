class Solution {
public:
    int arrangeCoins(int n) {
        unsigned long long int N = n;        
        unsigned long long int i = 1;
        while (pow(i,2) + i <= 2 * N) i++;
        return i - 1;
    }
};
