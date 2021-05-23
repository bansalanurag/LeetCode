class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        
        int ans = 0;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int, int>> Q;
                    Q.push(make_pair(i, j));
                    while (!Q.empty()) {
                        int r = Q.front().first, c = Q.front().second; 
                        visited[r][c] = true;
                        for (int k = 0; k < 4; ++k) {
                            int rr = r + dr[k];
                            int cc = c + dc[k];
                            if (rr < 0 || cc < 0) { ans += 1; continue; }
                            if (rr >= n || cc >= m) { ans += 1; continue; }
                            if (grid[rr][cc] == 0) { ans += 1; continue; }
                            if (visited[rr][cc]) continue;
                            
                            visited[rr][cc] = true;
                            Q.push(make_pair(rr, cc));
                        }
                        Q.pop();
                    }
                }
            }
        }        
        return ans;
    }
};
