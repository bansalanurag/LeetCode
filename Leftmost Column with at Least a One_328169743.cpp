/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &B) {
        int ans = INT_MAX;
        vector<int> size = B.dimensions();
        int rows = size[0];
        int cols = size[1];
        
        for (int i = 0; i < rows; ++i) {
            int temp = -1;
            int low = 0, high = cols - 1;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int val = B.get(i, mid);
                if (val == 1) {
                    temp = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                } 
            }
            
            if (temp != -1) {
                ans = min(ans, temp);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
