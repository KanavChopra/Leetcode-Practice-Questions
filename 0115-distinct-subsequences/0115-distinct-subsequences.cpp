// Approach:
// dp[i][j] means number of distinct subsequences of t[0...i - 1] in s[0...j - 1];
// Then we have the following cases:
// 1. dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
// 2. dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j - 1];
// 3. Boundry case 1: dp[i][0] = 0 for all positive i, because non-empty string will have no susequence in any string.
// 4. Boundry case 2: dp[0][j] = 1, because an empty string will have exactly one subsequence in any string

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return (int) dp[m][n];
    }
};