struct Cell {
    int row;
    int col;
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
        Add each rotted orange to a queue
        Execute multi-node bfs
        Each level of iteration that bfs rouns is a minute of time
        If fresh fruit exist in the grid after bfs has terminated, they are unreachable so it is impossible for all fruit to be rotted
        */

        const int EMPTY = 0;
        const int FRESH = 1;
        const int ROTTEN = 2;

        int height = grid.size();
        int width = grid[0].size();
        int freshFruitCount = 0;
        queue<Cell> rottenFruits;
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (grid[row][col] == FRESH) {
                    ++freshFruitCount;
                }
                else if (grid[row][col] == ROTTEN) {
                    rottenFruits.push({row, col});
                }
            }
        }
        if (freshFruitCount == 0) {
            return 0;
        }

        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};

        int time = 0;
        while (!rottenFruits.empty()) {
            ++time;
            for (int fruit = 0, numRotten = rottenFruits.size(); fruit < numRotten; ++fruit) {
                Cell rottenFruit = rottenFruits.front();
                rottenFruits.pop();

                for (int direction = 0; direction < 4; ++direction) {
                    int newRow = rottenFruit.row + dRow[direction];
                    int newCol = rottenFruit.col + dCol[direction];

                    if (newRow >= 0 && newCol >= 0 && newRow < height && newCol < width) {
                        if (grid[newRow][newCol] == FRESH) {
                            --freshFruitCount;
                            grid[newRow][newCol] = ROTTEN;
                            rottenFruits.push({newRow, newCol});
                        }
                    }
                }
            }
        }

        if (freshFruitCount == 0) {
            return time - 1;
        }
        return -1;
    }
};
