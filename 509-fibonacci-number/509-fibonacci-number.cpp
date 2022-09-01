class Solution {
public:
    // int solve(int n, vector<int> &dp) {
    //     if (n == 0 || n == 1) {
    //         return n;
    //     }
    //     if (dp[n] != -1) {
    //         return dp[n];
    //     }
    //     return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    // }
    int fib(int n) {
        // Recursion
        // if (n == 0 || n == 1) {
        //     return n;
        // }
        // return fib(n - 1) + fib(n - 2);
        
        
        // Memoization
        // vector<int> dp(n + 1, -1);
        // return solve(n, dp);
        
        
        // Tabulation
        // vector<int> dp(n + 1, -1);
        // dp[0] = 0;
        // dp[1] = 1;
        // for (int i = 2; i <= n; ++i) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];
        
        
        // Space Optimised
        if (n == 0 || n == 1) {
            return n;
        }
        int a = 0;
        int b = 1;
        for (int i = 2; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};