class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            std::unordered_set<char> seen;
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (seen.count(board[i][j])) {
                    return false;
                }
                
                seen.insert(board[i][j]);
            }
        }

        for (int i = 0; i < board.size(); i++) {
            std::unordered_set<char> seen;
            for (int j = 0; j < board.size(); j++) {
                if (board[j][i] == '.') {
                    continue;
                }

                if (seen.count(board[j][i])) {
                    return false;
                }
                
                seen.insert(board[j][i]);
            }
        }

        for (int c = 0; c < board.size(); c += 3) {
            for (int r = 0; r < board.size(); r += 3) {
                std::unordered_set<char> seen;
                for (int i = c; i < c + 3; i++) {
                    for (int j = r; j < r + 3; j++) {
                        if (board[i][j] == '.') {
                            continue;
                        }

                        if (seen.count(board[i][j])) {
                            return false;
                        }

                        seen.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};
