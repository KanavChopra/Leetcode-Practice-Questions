class Solution {
private:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        // If we have matched all the character of the required string
        if (j < 0) {
            return 1;
        }
        // If we have exhausted the first string and there is still matching
        // to be done on string second
        if (i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == t[j]) {
            return dp[i][j] = solve(s, t, i - 1, j, dp) + solve(s, t, i - 1, j - 1, dp);
        }
        return dp[i][j] = solve(s, t, i - 1, j, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, t, n - 1, m - 1, dp);
    }
};