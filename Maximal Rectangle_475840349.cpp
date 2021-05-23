class Solution {
public:
    
    vector<int> smallestOnLeft(vector<int> &A) {
        int n = A.size();
        vector<int> left(n);
        stack<pair<int, int>> S;
        
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                left[i] = -1;
                S.push({A[i], i});
                continue;
            }
            
            if (S.top().first < A[i])
                left[i] = S.top().second;
            else {
                while (!S.empty() && S.top().first >= A[i])
                    S.pop();
                left[i] = S.empty() ? -1 : S.top().second;
            }
            
            S.push({A[i], i});
        }
        
        return left;
    }
    
    vector<int> smallestOnRight(vector<int> &A) {
        int n = A.size();
        vector<int> right(n);
        stack<pair<int, int>> S;
        
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                right[i] = n;
                S.push({A[i], i});
                continue;
            }
            
            if (S.top().first < A[i])
                right[i] = S.top().second;
            else {
                while (!S.empty() && S.top().first >= A[i])
                    S.pop();
                right[i] = S.empty() ? n : S.top().second;
            }
            
            S.push({A[i], i});
        }
        
        return right;
    }
    
    
    int largestRectangle(vector<int> &A) {
        if (A.empty())
            return 0;
        
        vector<int> left = smallestOnLeft(A);
        vector<int> right = smallestOnRight(A);
        
        int maxArea = 0;
        for (int i = 0; i < A.size(); ++i) {
            maxArea = max(maxArea, (right[i] - left[i] - 1) * A[i]);
        }
        
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> A(n, vector<int> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) 
                A[i][j] = matrix[i][j] == '1' ? 1 : 0;
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                A[i][j] = A[i][j] ? A[i - 1][j] + A[i][j] : 0;
            }
        }
        
        int maxArea = 0;
        for (auto i : A) {
            maxArea = max(maxArea, largestRectangle(i));
        }
        
        return maxArea;
    }
};
