class Solution {
public:
    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int sx, int sy, int n, int m) {
        if(visited[sx][sy]) {
            return 0;
        }
        visited[sx][sy] = 1;
        int count = 1;
        int dXdY[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < 4; ++i) {
            int newX = sx + dXdY[i][0];
            int newY = sy + dXdY[i][1];
            if (isValid(newX, newY, n, m) && (grid[newX][newY] == 1) && !visited[newX][newY]) {
                count += dfs(grid, visited, newX, newY, n, m);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    mx = max(mx, dfs(grid, visited, i, j, n, m));
                }
            }
        }
        return mx;
    }
};