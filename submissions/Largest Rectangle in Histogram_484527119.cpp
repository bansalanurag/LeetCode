class Solution {
public:
    
    vector<int> smallerOnLeft(vector<int> nums) {
        int n = nums.size();
        vector<int> left(n);
        stack<pair<int, int>> S;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                left[i] = -1;                
            } else {
                while (!S.empty() && S.top().first >= nums[i])
                    S.pop();
                
                left[i] = S.empty() ? -1 : S.top().second;
            }
            
            S.push({nums[i], i});
        }
        
        return left;
    }

    vector<int> smallerOnRight(vector<int> nums) {
        int n = nums.size();
        vector<int> right(n);
        stack<pair<int, int>> S;
        
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                right[i] = n;                
            } else {
                while (!S.empty() && S.top().first >= nums[i])
                    S.pop();
                
                right[i] = S.empty() ? n : S.top().second;
            }
            
            S.push({nums[i], i});
        }
        
        return right;
    }

    
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        
        vector<int> left = smallerOnLeft(heights);
        vector<int> right = smallerOnRight(heights);
        
        int area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            area = max(area, heights[i] * (right[i] - left[i] - 1));
        }
        
        return area;
    }
};
