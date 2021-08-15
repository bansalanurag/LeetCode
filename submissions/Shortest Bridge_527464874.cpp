class Solution {
public:
    
    vector<vector<bool>> visited;
    
    void exploreIsland(vector<vector<int>>& grid, int row, int col, set<pair<int, int>>& island) {
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        queue<pair<int, int>> Q;
        
        Q.push({row, col});
        visited[row][col] = true;
        
        while (!Q.empty()) {
            pair<int, int> currentPlace = Q.front(); Q.pop();
            island.insert(currentPlace);
            int r = currentPlace.first;
            int c = currentPlace.second;            
            
            for (int i = 0; i < 4; ++i) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                
                if (rr < 0 || cc < 0 || rr >= grid.size() || cc >= grid[0].size()) continue;
                if (visited[rr][cc] || grid[rr][cc] == 0) continue;
                
                Q.push({rr, cc});
                visited[rr][cc] = true;
            }
        }        
    }
    
    int manhattenDist(pair<int, int>& p, pair<int, int>& q) {
        return abs(p.first - q.first) + abs(p.second - q.second) - 1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size(); 
        int cols = grid[0].size();
        set<pair<int, int>> islandA, islandB;    
        visited.resize(rows, vector<bool> (cols, false));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!visited[i][j] && grid[i][j]) {
                    if (islandA.empty()) {
                        exploreIsland(grid, i, j, islandA);
                    } else {                        
                        exploreIsland(grid, i, j, islandB);
                    }
                }
            }
        }
        
        int shortestDist = rows * cols + 1;
        for (pair<int, int> p : islandA) {
            for (pair<int, int> q : islandB) {
                shortestDist = min(shortestDist, manhattenDist(p, q));
            }
        }
        
        return shortestDist;
    }
};