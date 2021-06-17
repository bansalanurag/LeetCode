class Solution {
public:
    
    // Time : O(N) , Space : O(1)
    // N -> size of input array.
    
    bool increasingTriplet(vector<int>& nums) {
        int smallest = nums[0];
        int secondSmallest = INT_MAX;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < smallest) {
                smallest = nums[i];
            } else if (nums[i] < secondSmallest && nums[i] > smallest) {
                secondSmallest = nums[i];
            } else if (nums[i] > secondSmallest) {
                // Fount Third smallest and the required sequence.
                return true;
            }
        }
        
        return false;
    }
};