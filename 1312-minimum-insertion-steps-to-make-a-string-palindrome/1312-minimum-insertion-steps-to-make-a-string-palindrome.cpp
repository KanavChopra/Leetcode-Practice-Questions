class Solution {
    int solve(string &s, int start, int end, vector<vector<int>> &dp) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        if (s[start] == s[end]) {
            return dp[start][end] = solve(s, start + 1, end - 1, dp);
        } else {
            int insertAtBeginning = 1 + solve(s, start, end - 1, dp);
            int insertAtEnd = 1 + solve(s, start + 1, end, dp);
            return dp[start][end] = min(insertAtBeginning, insertAtEnd);
        }
    }
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};