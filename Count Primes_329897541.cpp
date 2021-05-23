class Solution {
public:
    vector<bool> primes;
    
    void sieve(int n) {
        primes[0] = primes[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (primes[i]) {
                int j = i + i;
                for (; j <= n; j += i) {
                    primes[j] = false;
                }            
            }
        }
    }
    
    int countPrimes(int n) {
        if (n <= 1) return 0;
        
        int ans = 0;
        primes.resize(n + 1, true);
        sieve(n);
        for (int i = 0; i < n; ++i) if (primes[i]) ans += 1;
        return ans;
    }
};
