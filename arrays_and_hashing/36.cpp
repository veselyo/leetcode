class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            // Check rows
            for (int i = 0; i < 9; i++) {
                std::unordered_set<char> row = {};
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        continue;
                    }
                    if (row.find(board[i][j]) != row.end()) {
                        return false;
                    }
                    row.insert(board[i][j]);
                }
            }
    
            // Check columns
            for (int i = 0; i < 9; i++) {
                std::unordered_set<char> col = {};
                for (int j = 0; j < 9; j++) {
                    if (board[j][i] == '.') {
                        continue;
                    }
                    if (col.find(board[j][i]) != col.end()) {
                        return false;
                    }
                    col.insert(board[j][i]);
                }
            }
    
            // Check 3x3
            for (int r = 0; r < 9; r = r + 3) {
                for (int c = 0; c < 9; c = c + 3) {
                    std::unordered_set<char> square = {};
                    for (int i = r; i < r + 3; i++) {
                        for (int j = c; j < c + 3; j++) {
                            if (board[i][j] == '.') {
                                continue;
                            }
                            if (square.find(board[i][j]) != square.end()) {
                                return false;
                            }
                            square.insert(board[i][j]);
                        }
                    }
                }
            }
            return true;
        }
    };    