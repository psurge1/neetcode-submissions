class Solution {
private:
    bool searchWord(int row, int col, int idx, const string& word, vector<vector<char>>& board) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || idx >= word.size()) {
            return false;
        }
        if (board[row][col] != word[idx]) {
            return false;
        }
        if (idx == word.size() - 1) {
            return true;
        }

        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};
        board[row][col] = '.';
        for (int direction = 0; direction < 4; ++direction) {
            int newRow = row + dRow[direction];
            int newCol = col + dCol[direction];
            if (searchWord(newRow, newCol, idx + 1, word, board)) {
                return true;
            }
        }
        board[row][col] = word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int height = board.size();
        int width = board[0].size();
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (searchWord(row, col, 0, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};
