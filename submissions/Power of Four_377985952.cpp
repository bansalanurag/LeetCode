class Solution {
public:
    bool isPowerOfFour(long num) {
        if ((num & (num - 1)) || num <= 0)
            return false;
        
        int count = 0;
        while (num) {
            count += 1;
            num >>= 1;
        }        
        count -= 1;
        
        if (!(count&1)) return true;
        return false;        
    }
};
