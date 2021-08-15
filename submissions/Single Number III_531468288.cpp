class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long totalXor = 0;
        for (int element : nums) {
            totalXor ^= element;
        }
        
        totalXor &= (-totalXor);
        int numA = 0, numB = 0;
        
        for (int element : nums) {
            if ((element&totalXor))
                numA ^= element;
            else
                numB ^= element;
        }
        
        vector<int> ans{numA, numB};
        return ans;
    }
};