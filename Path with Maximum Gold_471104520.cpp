class Solution {
public:
    
    int dfs(vector<vector<int>> &G, int n, int m, int i, int j, vector<vector<bool>> &visited) {
        if (i < 0 || j < 0 || i >= n || j >= m || G[i][j] == 0)
            return 0;
        
        if (visited[i][j] )
            return 0;
        
        visited[i][j] = true;
        int left = dfs(G, n, m, i, j - 1, visited);
        int right = dfs(G, n, m, i, j + 1, visited);
        int up = dfs(G, n, m, i - 1, j, visited);
        int down = dfs(G, n, m, i + 1, j, visited);
        
        visited[i][j] = false;
        return max({left, right, down, up}) + G[i][j];
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        if (grid.empty()) return ans;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    ans = max(ans, dfs(grid, n, m, i, j, visited));
                }
            }
        }
        
        return ans;
    }
};
