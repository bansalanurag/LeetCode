class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int up = i - 1 >= 0 ? mat[i - 1][j] : 0;
                int left = j - 1 >= 0 ? mat[i][j - 1] : 0;                
                int diag = i - 1 >= 0 && j - 1 >= 0? mat[i - 1][j - 1] : 0;
                mat[i][j] += up + left - diag;
            }    
        }        
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int a = i - k < 0 ? 0 : i - k;
                int c = i + k >= n ? n - 1 : i + k;
                int b = j - k < 0 ? 0 : j - k;
                int d = j + k >= m ? m - 1 : j + k;
                
                ans[i][j] = mat[c][d] - (b - 1 >= 0 ? mat[c][b - 1] : 0) - (a - 1 >= 0 ? mat[a - 1][d] : 0) + (a - 
                    1 >= 0 && b - 1 >= 0 ? mat[a - 1][b - 1] : 0);                
            }
        }
        
        return ans;
    }
};
