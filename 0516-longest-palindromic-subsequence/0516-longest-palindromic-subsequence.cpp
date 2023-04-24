class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j] denotes the lenght of the longest lps
        // between indexes i and j
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            // if there is only one character
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        // [0...n - 1] contains our answer becuase it denotes to
        // give the length of lps starting at 0 index and ending
        // at n - 1 index which is basically the complete string/
        return dp[0][n - 1];
    }
};