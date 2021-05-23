class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        
        int nodesAtThisLevel = 0;
        int nodesAtNextLevel = 0;
        int numOfFreshOranges = 0;
        queue<pair<int, int>> rotten; 
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                    visited[i][j] = true;   
                    nodesAtThisLevel += 1;
                } else if (grid[i][j] == 1) {
                    numOfFreshOranges += 1;
                }
            }
        }
        
        if (rotten.empty()) return numOfFreshOranges != 0 ? -1 : 0;
        
        while (!rotten.empty()) {            
            int r = rotten.front().first;
            int c = rotten.front().second;
            
            for (int k = 0; k < 4; ++k) {
                int rr = r + dr[k];
                int cc = c + dc[k];
                
                if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
                if (visited[rr][cc]) continue;
                if (grid[rr][cc] == 0 || grid[rr][cc] == 2) continue;
                
                rotten.push({rr, cc});
                visited[rr][cc] = true;
                nodesAtNextLevel += 1;
                numOfFreshOranges -= 1;
            }
            
            rotten.pop();
            nodesAtThisLevel -= 1;
            if (nodesAtThisLevel == 0) {
                nodesAtThisLevel = nodesAtNextLevel;
                nodesAtNextLevel = 0;
                ans += 1;
            }            
        }
        
        return numOfFreshOranges != 0 ? -1 : ans - 1;
    }
};
