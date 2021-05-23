class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        vector<vector<int>> ans(n, vector<int> (m, 0));
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        int nodeOnThisLevel = q.size();
        int nodeOnNextLevel = 0;
        int level = 1;
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            
            for (int k = 0; k < 4; ++k) {
                int rr = r + dr[k];
                int cc = c + dc[k];
                
                if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
                if (visited[rr][cc]) continue;
                
                q.push({rr, cc});
                visited[rr][cc] = true;
                nodeOnNextLevel += 1;
                ans[rr][cc] = level;
            }
            
            q.pop();
            nodeOnThisLevel -= 1;
            if (nodeOnThisLevel == 0) {
                nodeOnThisLevel = nodeOnNextLevel;
                nodeOnNextLevel = 0;
                level += 1;
            }
        }
        
        return ans;
    }
};
