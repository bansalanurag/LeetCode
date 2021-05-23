class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int firstElement = nums[0];
        
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target)
                return m;
            
            bool am_big = nums[m] >= firstElement;
            bool target_big = target >= firstElement;
            
            if (am_big == target_big) {
                if (nums[m] < target)
                    l = m + 1;
                else
                    h = m - 1;
            } else {
                if (am_big)
                    l = m + 1;
                else
                    h = h - 1;
            }
        }
        
        return -1;
    }
};
