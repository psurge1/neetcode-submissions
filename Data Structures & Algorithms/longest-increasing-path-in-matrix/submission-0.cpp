class Solution {
private:
    int dfs(int row, int col, int height, int width, int& maxPathLength, vector<vector<int>>& cache, const vector<vector<int>>& matrix) {
        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};
        if (cache[row][col] == 0) {
            for (int direction = 0; direction < 4; ++direction) {
                int newRow = row + dRow[direction];
                int newCol = col + dCol[direction];
                if (newRow >= 0 && newCol >= 0 && newRow < height && newCol < width) {
                    if (matrix[newRow][newCol] > matrix[row][col]) {
                        cache[row][col] = max(cache[row][col], dfs(newRow, newCol, height, width, maxPathLength, cache, matrix));
                    }
                }
            }
            ++cache[row][col];
            maxPathLength = max(maxPathLength, cache[row][col]);
        }
        return cache[row][col];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        vector<vector<int>> cache(height, vector<int>(width, 0));
        int maxPathLength = 0;
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                // run dfs
                dfs(row, col, height, width, maxPathLength, cache, matrix);
            }
        }

        return maxPathLength;
    }
};
