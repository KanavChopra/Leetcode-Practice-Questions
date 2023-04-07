class Solution {
    bool is_valid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    int bfs(vector<vector<int>> &grid, int n, int m) {
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i * j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            for (auto &direction : directions) {
                int new_x = x + direction.first;
                int new_y = y + direction.second;
                if (is_valid(new_x, new_y, n, m) && !visited[new_x][new_y] && grid[new_x][new_y] == 1) {
                    q.push({new_x, new_y});
                    visited[new_x][new_y] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = bfs(grid, n, m);
        return res;
    }
};