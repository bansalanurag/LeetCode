class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> result = image;
        
        int color;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        queue<pair<int, int>> Q;            
        vector<vector<bool>> visited(n, vector<bool> (m, false));
                
        color = image[sr][sc];
        visited[sr][sc] = true;
        Q.push({sr, sc});
        while (!Q.empty()) {
            int r = Q.front().first;
            int c = Q.front().second;
            result[r][c] = newColor;
            Q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                
                if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
                if (visited[rr][cc]) continue;
                if (image[rr][cc] != color) continue;
                
                visited[rr][cc] = true;
                result[rr][cc] = color;
                Q.push({rr, cc});
            }
        }
        
        return result;
    }
};
