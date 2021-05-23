class Solution {
public:
    
    void sinkBattleShip(vector<vector<char>>& board, int I, int J) {        
        int i = I, j = J;
        while (j < board[i].size() && board[i][j] == 'X') {
            board[i][j] = '.';
            j += 1;
        }
        i += 1;
        while (i < board.size() && board[i][J] == 'X') {
            board[i][J] = '.';
            i += 1;
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'X') {
                    sinkBattleShip(board, i, j);
                    cnt += 1;   
                    // for (auto i : board) {
                    //     for (auto j : i) cout << j << " ";
                    //     cout << endl;
                    // }
                    // cout << endl;                    
                }
            }
        }
        return cnt;
    }
};
