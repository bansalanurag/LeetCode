class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        for (int k = 0; k < n; ++k) {
            vector<int> diag;
            int j = 0;
            for (int i = k; i < n && j < m; ++i, ++j) diag.emplace_back(A[i][j]);
            sort(diag.begin(), diag.end());
            j = 0;
            int l = 0;
            for (int i = k; i < n && j < m; ++i, ++j) ans[i][j] = diag[l++];            
        }
        for (int k = 1; k < m; ++k) {
            vector<int> diag;
            int i = 0;
            for (int j = k; i < n && j < m; ++i, ++j) diag.emplace_back(A[i][j]);
            sort(diag.begin(), diag.end());
            i = 0;
            int l = 0;
            for (int j = k; i < n && j < m; ++i, ++j) ans[i][j] = diag[l++];            
        }
        return ans;
    }
};
