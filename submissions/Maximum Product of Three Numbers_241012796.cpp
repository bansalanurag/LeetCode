class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        
        if (nums.size() == 3)
            return nums[0] * nums[1] * nums[2];
        
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        int a = INT_MAX, b = INT_MAX;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];                
            }
            else if (nums[i] > second) {
                third = second;
                second = nums[i];
            }
            else if (nums[i] > third)
                third = nums[i];
            
            if (nums[i] < a) {
                b = a;
                a = nums[i];
            }
            else if (nums[i] < b)
                b = nums[i];                 
        }
        return max((first * second * third), (a * b * first)); 
    }
};
