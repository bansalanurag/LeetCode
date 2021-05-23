class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        vector<int> primes{2, 3, 5};
        for (int i : primes)
            while (num % i == 0)    num /= i;
        return (num == 1 ? true : false);        
    }
};
