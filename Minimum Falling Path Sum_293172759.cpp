class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int ans = INT_MAX;
        if (A.size() == 1) return A[0][0];        
        
        for (int i = 1; i < A.size(); ++i) {            
            for (int j = 0; j < A[i].size(); ++j) {
                if (j == 0)
                    A[i][j] = min(A[i - 1][j], A[i - 1][j + 1]) + A[i][j];
                else if (j == A[i].size() - 1)
                    A[i][j] = min(A[i - 1][j], A[i - 1][j - 1]) + A[i][j];
                else
                    A[i][j] = min(A[i - 1][j], min(A[i - 1][j + 1], A[i- 1][j - 1])) + A[i][j];
            }
        }
        for (int i = 0; i < A[0].size(); ++i) ans = min(ans, A[A.size() - 1][i]);
        return ans;
    }
};
