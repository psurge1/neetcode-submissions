class Solution {
private:
    int dfs(int row, int col, int height, int width, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (row < 0 || col < 0 || row >= height || col >= width) {
            return 0;
        }
        if (grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }
        visited[row][col] = true;

        return 1 + dfs(row - 1, col, height, width, grid, visited)
        + dfs(row + 1, col, height, width, grid, visited)
        + dfs(row, col - 1, height, width, grid, visited)
        + dfs(row, col + 1, height, width, grid, visited);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));

        int max_area = 0;

        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                max_area = max(max_area, dfs(row, col, height, width, grid, visited));
            }
        }

        return max_area;
    }
};
