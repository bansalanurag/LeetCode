class Solution {
public:
    bool isPerfectSquare(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        for (long i = 1; i * i <= n; i++) {
            if ((n % i == 0) && (n / i == i)) { 
                return true; 
            } 
        } 
        return false; 
    }
};
