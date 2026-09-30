class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        height = len(grid)
        width = len(grid[0])

        def is_valid(row, col):
            return row >= 0 and col >= 0 and row < height and col < width and grid[row][col] == 1
        
        def sink_island(row, col):
            d_row = [-1, 1, 0, 0]
            d_col = [0, 0, -1, 1]
            island_size = 1
            for d in range(4):
                new_row = row + d_row[d]
                new_col = col + d_col[d]
                if is_valid(new_row, new_col):
                    grid[new_row][new_col] = 0
                    island_size += sink_island(new_row, new_col)
            return island_size

        max_island_area = 0
        for row in range(height):
            for col in range(width):
                if is_valid(row, col):
                    grid[row][col] = 0
                    max_island_area = max(max_island_area, sink_island(row, col))
        
        return max_island_area