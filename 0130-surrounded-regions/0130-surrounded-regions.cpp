class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    bool valid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<tuple<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i * j == 0 || i == n - 1 || j == m - 1) {
                    if (board[i][j] == 'O') {
                        q.push(make_tuple(i, j));
                        visited[i][j] = 1;
                    }
                }
            }
        }
        while (!q.empty()) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            q.pop();
            for (const auto &direction : directions) {
                int nx = x + direction.first;
                int ny = y + direction.second;
                if (valid(nx, ny, n, m) && !visited[nx][ny] && board[nx][ny] == 'O') {
                    visited[nx][ny] = 1;
                    q.push(make_tuple(nx, ny));
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};