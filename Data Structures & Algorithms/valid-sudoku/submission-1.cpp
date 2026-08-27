class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); row++) {
            std::unordered_set<char> seen;
            for (int col = 0; col < board.size(); col++) {
                if (board[row][col] == '.') continue;
                if (seen.contains(board[row][col])) {
                    return false;
                }

                seen.insert(board[row][col]);
            }
        }

        for (int col = 0; col < board.size(); col++) {
            std::unordered_set<char> seen;
            for (int row = 0; row < board.size(); row++) {
                if (board[row][col] == '.') continue;
                if (seen.contains(board[row][col])) {
                    return false;
                }

                seen.insert(board[row][col]);
            }
        }

        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                std::unordered_set<char> seen;
                for (int row = i; row < i + 3; row++) {
                    for (int col = j; col < j + 3; col++) {
                        if (board[row][col] == '.') continue;
                        if (seen.contains(board[row][col])) {
                            return false;
                        }

                        seen.insert(board[row][col]);
                    }
                }
            }
        }

        return true;
    }
};