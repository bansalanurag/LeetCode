class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>> &board, vector<vector<bool>> &visited) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (board[i][j] == 'X' || visited[i][j]) return;
                
        visited[i][j] = true;
        dfs(i - 1, j, n, m, board, visited);
        dfs(i + 1, j, n, m, board, visited);
        dfs(i, j - 1, n, m, board, visited);
        dfs(i, j + 1, n, m, board, visited);
    }
    
    void solve(vector<vector<char>>& board) {        
        if (board.empty()) return;
        int n = board.size();        
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i >= 1 && i <= n - 2) &&  (j >= 1 && j <= m - 2)) continue;
                if (!visited[i][j] && board[i][j] == 'O')
                    dfs(i, j, n, m, board, visited);
            }
        }
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (!visited[i][j])
                    board[i][j] = 'X';
            }
        }        
    }
};
