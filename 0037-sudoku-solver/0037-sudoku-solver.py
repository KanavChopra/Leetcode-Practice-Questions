class Solution:
    def isValid(self, row, col, board, val):
        for k in range(9):
            # Check current row
            if board[row][k] == val:
                return False
            # Check current column
            if board[k][col] == val:
                return False
            # Check current submatrix of size 3 x 3
            if board[3 * (row // 3) + k // 3][3 * (col // 3) + k % 3] == val:
                return False
        return True
    
    def solve(self, board):
        n = len(board)
        for i in range(n):
            for j in range(n):
                # Check empty cell
                if board[i][j] == '.':
                    # Try all values for current cell with values from '1' to '9'
                    for val in map(str, range(1, 10)):
                        if self.isValid(i, j, board, val):
                            board[i][j] = val
                            if self.solve(board):
                                return True
                            else:
                                # Backtrack
                                board[i][j] = '.'
                    # If after trying all the values and we don't get the answer,
                    # this means there is no possible solution and return False
                    return False
        return True
    
    def solveSudoku(self, board):
        self.solve(board)
