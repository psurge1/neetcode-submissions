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

    int bfs(int row, int col, int height, int width, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        deque<pair<int, int>> q;
        q.push_back(make_pair(row, col));
        visited[row][col] = true;
        if (grid[row][col] == 0) {
            return 0;
        }

        int island_size = 0;
        while (!q.empty()) {
            pair<int, int> point = q.front();
            int r = point.first;
            int c = point.second;

            ++island_size;

            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};
            for (int d = 0; d < 4; ++d) {
                int new_r = r + dr[d];
                int new_c = c + dc[d];

                if (new_r < 0 || new_c < 0 || new_r >= height || new_r >= width || visited[new_r][new_c] || grid[new_r][new_c] == 0) {
                    continue;
                }
                q.push_back(make_pair(new_r, new_c));
            }
        }

        return island_size;
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
