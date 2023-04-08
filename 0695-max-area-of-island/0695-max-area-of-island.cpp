class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y, int n, int m) {
        visited[x][y] = 1;
        int cnt = 1;
        for (const auto &direction : directions) {
            int nx = x + direction.first;
            int ny = y + direction.second;
            if (isValid(nx, ny, n, m) && grid[nx][ny] == 1 && !visited[nx][ny]) {
                cnt += dfs(grid, visited, nx, ny, n, m);
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = dfs(grid, visited, i, j, n, m);
                    mx = max(mx, area);
                }
            }
        }
        return mx;
    }
};