class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxOnes = 0;
        for (int i : nums) {
            if (i) count += 1;
            else {
                maxOnes = max(maxOnes, count);
                count = 0;
            }
        }
        
        return max(maxOnes, count);
    }
};
