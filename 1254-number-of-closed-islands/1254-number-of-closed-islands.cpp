class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    void fill(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size() || grid[x][y] == 1) {
            return;
        }
        grid[x][y] = 1;
        for (auto &direction : directions) {
            fill(grid, x + direction.first, y + direction.second);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (i * j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1) {
                    fill(grid, i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++cnt;
                    fill(grid, i, j);
                }
            }
        }
        return cnt;
    }
};