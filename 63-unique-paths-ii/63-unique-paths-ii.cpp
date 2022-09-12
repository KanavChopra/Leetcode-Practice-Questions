class Solution {
public:
    int solve(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp) {
        if (m == 0 && n == 0) {
            return 1;
        }
        if (m < 0 || n < 0) {
            return 0;
        }
        if (grid[m][n]) {
            return 0;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        int left = solve(grid, m, n - 1, dp);
        int up = solve(grid, m - 1, n, dp);
        return dp[m][n] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid[0][0]) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, m - 1, n - 1, dp);
    }
};