class Solution {
private:
    int dfs(int row, int col, int width, int height, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (row < 0 || row >= height || col < 0 || col >= width) {
            return 0;
        }
        if (visited[row][col] || grid[row][col] == '0') {
            return 0;
        }
        visited[row][col] = true;
        
        vector<int> dRow = {0, 0, -1, 1};
        vector<int> dCol = {-1, 1, 0, 0};
        for (int d = 0; d < 4; ++d) {
            dfs(row + dRow[d], col + dCol[d], width, height, grid, visited);
        }

        return 1;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int num_islands = 0;
        vector<vector<bool>> visited(height, vector<bool>(width, false));

        for (int row = 0; row < height; ++row) {
            for (int col = 0, width = grid[row].size(); col < width; ++col) {
                num_islands += dfs(row, col, width, height, grid, visited);
            }
        }

        return num_islands;
    }
};
