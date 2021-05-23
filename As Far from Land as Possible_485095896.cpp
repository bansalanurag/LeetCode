class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int maxDist = 0;
        int n = grid.size(), m = grid[0].size();
        
        if (n == 0)
            return maxDist;
    
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        queue<pair<int, int>> Q;        
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};        
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    Q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        if (Q.empty())
            return -1;
        
        int curr = Q.size(), next = 0;
        while (!Q.empty()) {
            pair<int, int> p = Q.front(); Q.pop();
            curr -= 1;
            int r = p.first;
            int c = p.second;
            
            for (int k = 0; k < 4; ++k) {
                int rr = r + dr[k];
                int cc = c + dc[k];
                
                if (rr < 0 || cc < 0 || rr >= n || cc >= m || visited[rr][cc])
                    continue;
                
                Q.push({rr,cc});
                visited[rr][cc] = true;
                next += 1;
            }
            
            if (curr == 0 && !Q.empty()) {
                maxDist += 1;
                curr = next;
                next = 0;
            }
        }
        
        return maxDist ? maxDist : -1;
    }
};
