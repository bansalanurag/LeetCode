class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int ans = 0;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        int n = grid.size(), m = grid[0].size();
        bool visited[n][m];
        memset(visited, false, sizeof(visited));        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int area = 1;
                    queue<pair<int, int>> Q;
                    Q.push({i, j});
                    visited[i][j] = true;
                    while (!Q.empty()) {
                        int r = Q.front().first;
                        int c = Q.front().second;                        
                        for (int k = 0; k < 4; ++k) {
                            int rr = r + dr[k];
                            int cc = c + dc[k];
                            if (rr < 0 || cc < 0) continue;
                            if (rr >= n || cc >= m) continue;
                            if (visited[rr][cc]) continue;
                            if (grid[rr][cc] == 0) continue;
                            Q.push({rr, cc});
                            visited[rr][cc] = true;
                            area += 1;
                        }
                        Q.pop();
                    }
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
