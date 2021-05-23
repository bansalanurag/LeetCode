class NumMatrix {
public:
    vector<vector<int>> P;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() != 0) {
            P.resize(matrix.size(), vector<int> (matrix[0].size(), 0));
            for (int i = 0; i < matrix.size(); ++i) 
                for (int j = 0; j < matrix[i].size(); ++j) 
                    P[i][j] = j == 0 ? matrix[i][j] : P[i][j - 1] + matrix[i][j];        
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int i = row1; i <= row2; ++i)
            ans += col1 == 0 ? P[i][col2] : P[i][col2] - P[i][col1 - 1];            
        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
