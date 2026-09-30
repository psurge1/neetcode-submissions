class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        height = len(grid)
        width = len(grid[0])
        INF = 2147483647

        def is_valid(row, col):
            return row >= 0 and col >= 0 and row < height and col < width and grid[row][col] == INF
        
        queue = deque()
        for row in range(height):
            for col in range(width):
                if grid[row][col] == 0:
                    queue.append((row, col))
        
        d_row = [-1, 1, 0, 0]
        d_col = [0, 0, -1, 1]
        while len(queue) > 0:
            level_length = len(queue)
            for _ in range(level_length):
                row, col = queue.popleft()
                for d in range(4):
                    new_row = row + d_row[d]
                    new_col = col + d_col[d]
                    if is_valid(new_row, new_col):
                        grid[new_row][new_col] = 1 + grid[row][col]
                        queue.append((new_row, new_col))