class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    bool is_valid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int x, int y, int n, int m) {
        visited[x][y] = 1;
        for (auto &direction : directions) {
            int _x = x + direction.first;
            int _y = y + direction.second;
            if (is_valid(_x, _y, n, m) && !visited[_x][_y] && grid[_x][_y] == '1') {
                dfs(grid, visited, _x, _y, n, m);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ++cnt;
                    dfs(grid, visited, i, j, n, m);
                }
            }
        } 
        return cnt;
    }
};