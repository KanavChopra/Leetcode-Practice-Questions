// Let dp[i] = min cost to reach the i-th floor.
// To reach the i-th floor, we have the following 2 ways:
//     1. Jump 1 step from (i - 1)th floor, dp[i] = dp[i - 1] + cost[i - 1];
//     2. Jump 2 step from (i - 2)th floor, dp[i] = dp[i - 2] + cost[i - 2];
// dp[i] = min(dp[i - 1], dp[i - 2]);


class Solution {
    private int solve(int[] cost, int n, int[] dp) {
        if (n == 0 || n == 1) {
            return cost[n];
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = cost[n] + Math.min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n + 1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = -1;
        }
        return Math.min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
}