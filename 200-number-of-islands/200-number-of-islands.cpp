class Solution {
public:
    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    void dfs(vector<vector<char>> &grid, int x, int y, int n, int m) {
        grid[x][y] = '0';
        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < 4; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (isValid(newX, newY, n, m) && grid[newX][newY] == '1') {
                dfs(grid, newX, newY, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};