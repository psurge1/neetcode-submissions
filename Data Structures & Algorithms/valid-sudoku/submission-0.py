class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        height = 9
        width = 9
        boxwidth = 3
        def validRows():
            for row in range(height):
                alreadyExists = [False] * 10
                for col in range(width):
                    if board[row][col] == ".":
                        continue
                    num = int(board[row][col])
                    if alreadyExists[num]:
                        return False
                    alreadyExists[num] = True
            return True

        def validCols():
            for col in range(width):
                alreadyExists = [False] * 10
                for row in range(height):
                    if board[row][col] == ".":
                        continue
                    num = int(board[row][col])
                    if alreadyExists[num]:
                        return False
                    alreadyExists[num] = True
            return True
        
        def validSubBoxes():
            for box in range(9):
                cornerRow = (box // 3) * 3
                cornerCol = (box % 3) * 3
                alreadyExists = [False] * 10
                for row in range(cornerRow, cornerRow + 3):
                    for col in range(cornerCol, cornerCol + 3):
                        if board[row][col] == ".":
                            continue
                        num = int(board[row][col])
                        if alreadyExists[num]:
                            print(box, num, alreadyExists)
                            return False
                        alreadyExists[num] = True
            return True
            
        """
        box 0, 1, 2, 3, 4, 5, 6, 7, 8
        col 0, 3, 6, 0, 3, 6, 0, 3, 6 = (box % 3) * 3
        row 0, 0, 0, 3, 3, 3, 6, 6, 6 = (box // 3) * 3
        """
        
        if not validRows():
            print("ROW")
            return False
        if not validCols():
            print("COL")
            return False
        if not validSubBoxes():
            print("BOX")
            return False
        return True