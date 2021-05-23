class Solution {
public:
    bool checkRows(vector<vector<char>> & board) {
        for (int i = 0; i < 9; ++i) {
            vector<bool> C(9, false);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (!C[board[i][j] - '0' - 1]) C[board[i][j] - '0' - 1] = true;
                    else return false;
                }
            }
        }
        return true;
    }
    
    bool checkCols(vector<vector<char>> & board) {
        for (int i = 0; i < 9; ++i) {
            vector<bool> C(9, false);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (!C[board[j][i] - '0' - 1]) C[board[j][i] - '0' - 1] = true;
                    else return false;
                }
            }
        }
        return true;
    }
    
    bool checkCube(vector<vector<char>> & board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> C(9, false);
                for (int l = i; l < i + 3; l++) {
                    for (int k = j; k < j + 3; k++) {
                        if (board[l][k] != '.') {
                            if (!C[board[l][k] - '0' - 1]) C[board[l][k] - '0' - 1] = true;
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        if (!checkRows(board)) return false;
        if (!checkCols(board)) return false;
        if (!checkCube(board)) return false;
        return true;
    }
};
