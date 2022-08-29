class Solution {
public:
    bool isValid(vector<vector<char>> &board, int x, int y) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
    void boundryDFS(vector<vector<char>> &board, int x, int y) {
        if (!isValid(board, x, y)) {
            return;
        }
        if (board[x][y] == 'O') {
            board[x][y] = '*';
        }
        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < 4; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (isValid(board, newX, newY) && board[newX][newY] == 'O') {
                boundryDFS(board, newX, newY);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        
        // moving over first and last col
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O')
                boundryDFS(board, i, 0);
            if (board[i][cols - 1] == 'O') 
                boundryDFS(board, i, cols - 1);
        }
        // moving over first and last row
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O')
                boundryDFS(board, 0, j);
            if (board[rows - 1][j] == 'O')
                boundryDFS(board, rows - 1, j);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
