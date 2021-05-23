class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t one = 0xFFFFFFFF;
        return (int) __builtin_popcount(one&n);
    }
};
