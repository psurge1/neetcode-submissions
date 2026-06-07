struct Cell {
    int row;
    int col;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        /*
        Input:
        - w x h grid, where each cell in the grid is either an X or an O
        - vector<vector<char>>&

        Output:
        - no return output
        - modify the input board

        Goal:
        - replace all connected regions of 'O's that are fully surrounded by 'X's
        
        Approach:
        - a surrounded region is one that doesn't touch the border of the grid
        - we can traverse every single 'O' on the border of the grid
            - this means we visit every cell in every region connected to the border of the grid
            - we change every 'O' we visit in this step with some intermediate value
        - after all border 'O' cells have been traversed, we re-visit every cell in the grid
            - if a cell still has the value 'O', that means it is surrounded as it wasn't reached by the border traversal step
                - we change these cells to 'X'
            - if a cell has the temporary value, we change it back to 'O' as it is connected to the border so it isn't surrounded
        */

        const char TRAVERSIBLE = 'O';
        const char OBSTACLE = 'X';
        const char TEMPORARY = 'T';
        queue<Cell> cellsToVisit;

        int height = board.size();
        int width = board[0].size();
        for (int row = 0; row < height; ++row) {
            if (board[row][0] == TRAVERSIBLE) {
                cellsToVisit.push({row, 0});
                board[row][0] = TEMPORARY;
            }
            if (board[row][width - 1] == TRAVERSIBLE) {
                cellsToVisit.push({row, width - 1});
                board[row][width - 1] = TEMPORARY;
            }
        }
        for (int col = 0; col < width; ++col) {
            if (board[0][col] == TRAVERSIBLE) {
                cellsToVisit.push({0, col});
                board[0][col] = TEMPORARY;
            }
            if (board[height - 1][col] == TRAVERSIBLE) {
                cellsToVisit.push({height - 1, col});
                board[height - 1][col] = TEMPORARY;
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

                if (newRow >= 0 && newCol >= 0 && newRow < height && newCol < width) {
                    if (board[newRow][newCol] == TRAVERSIBLE) {
                        board[newRow][newCol] = TEMPORARY;
                        cellsToVisit.push({newRow, newCol});
                    }
                }
            }
        }

        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (board[row][col] == TRAVERSIBLE) {
                    board[row][col] = OBSTACLE;
                }
                if (board[row][col] == TEMPORARY) {
                    board[row][col] = TRAVERSIBLE;
                }
            }
        }
    }
};
