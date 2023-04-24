class Solution {
    int solve(string &s, int start, int end, vector<vector<int>> &dp) {
        if (start > end) {
            return 0;
        }
        if (start == end) {
            return 1;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        if (s[start] == s[end]) {
            return dp[start][end] = 2 + solve(s, start + 1, end - 1, dp);
        } else {
            // since the characters are not same, so both cannot be the part
            // of our lps. so we recur on the substring either by removing the
            // first character or by either removing the last character, and
            // since we want the longest subsequence we take the max of both.
            return dp[start][end] = max(solve(s, start + 1, end, dp), solve(s, start, end - 1, dp));
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};