class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> ans(cols, -1);
        for (int ball = 0; ball < cols; ++ball) {
            int row = 0;
            int col = ball;
            while (row < rows) {
                if (col + 1 < cols && grid[row][col] == 1 && grid[row][col + 1] == 1) {
                    col += 1;
                    row += 1;
                } else if (col - 1 >= 0 && grid[row][col] == -1 && grid[row][col - 1] == -1) {
                    col -= 1;
                    row += 1;
                } else {
                    break;
                }
            }
                                                     
            ans[ball] = row == rows ? col : -1;
        }       
                                                     
        return ans;                                     
     }
};
