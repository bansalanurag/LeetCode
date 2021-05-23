class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1;
        int end = -1;
        int prevHigh = nums.size() - 1;
        int prevLow = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if ( nums[i] < nums[prevLow]) {
                end = i;
            } else {
                prevLow = i;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > nums[prevHigh]) {
                start = i;
            } else {
                prevHigh = i;
            }
        }

        return (start >= 0 && end >= 0) ? (end - start) + 1 : 0;
        
//         int lowestIndex = -1, highestIndex = -1;
        
//         for (int i = 0; i + 1 < nums.size(); ++i) {
//             if (nums[i] > nums[i + 1]) {
//                 lowestIndex = i;
//                 break;
//             }
//         }
        
//         for (int i = nums.size() - 1; i >= 1; --i) {
//             if (nums[i] <= nums[i - 1]) {
//                 highestIndex = i;
//                 break;
//             }
//         }
        
//         if (lowestIndex == -1) {
//             return 0;
//         }
//         // cout << lowestIndex << " " << highestIndex << "\n";
//         return highestIndex - lowestIndex + 1;
    }
};
