class Solution {
public:
    int dr[4] = { 1, -1, 0, 0};
    int dc[4] = { 0, 0, 1, -1};
    
    bool dfsWord(vector<vector<bool>> &visited, vector<vector<char>>& board, int i, int j, string word, int n, int 
        m, int k) {
    if (k == word.size() && word[k - 1] == board[i][j]) return true;
        visited[i][j] = true;   
        for (int l = 0; l < 4; ++l) {
            int rr = i + dr[l];
            int cc = j + dc[l];
    
            if (rr < 0 || cc < 0) continue;
            if (rr >= n || cc >= m) continue;
            if (visited[rr][cc]) continue;
            if (board[rr][cc] != word[k]) continue;
    
            if (dfsWord(visited, board, rr, cc, word, n, m, k + 1)) return true;
            else visited[rr][cc] = false;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        if (board.size() == 0) return false;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (word[0] == board[i][j]) {
                    vector<vector<bool>> visited(n, vector<bool> (m, false));
                    if (dfsWord(visited, board, i, j, word, n, m, 1)) return true;
                }
            }
        }
        return false;
    }
};
