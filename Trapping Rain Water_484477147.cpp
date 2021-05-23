class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0, leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            
            if (leftMax < rightMax) {
                ans += leftMax - height[left++];
            } else {
                ans += rightMax - height[right--];
            }
        }
        
        return ans;
    }
};
