struct Cell {
    int row;
    int col;
};

const int CHEST = 0;
const int TRAVERSIBLE = INT_MAX;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<Cell> cellsToVisit;
        int height = grid.size();
        int width = grid[0].size();
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (grid[row][col] == CHEST) {
                    cellsToVisit.push({row, col});
                }
            }
        }

        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};
        while (!cellsToVisit.empty()) {
            Cell cell = cellsToVisit.front();
            cellsToVisit.pop();

            for (int direction = 0; direction < 4; ++direction) {
                int newRow = cell.row + dRow[direction];
                int newCol = cell.col + dCol[direction];

                if (newRow >= 0 && newCol >= 0 && newRow < height && newCol < width && grid[newRow][newCol] == TRAVERSIBLE) {
                    grid[newRow][newCol] = 1 + grid[cell.row][cell.col];
                    cellsToVisit.push({newRow, newCol});
                }
            }
        }
    }
};
