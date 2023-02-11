// Let dp[i] = min cost to reach the i-th floor.
// To reach the i-th floor, we have the following 2 ways:
//     1. Jump 1 step from (i - 1)th floor, dp[i] = dp[i - 1] + cost[i - 1];
//     2. Jump 2 step from (i - 2)th floor, dp[i] = dp[i - 2] + cost[i - 2];
// dp[i] = min(dp[i - 1], dp[i - 2]);

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n + 1];
        for (int i = 2; i <= n; ++i) {
            int jumpOneStep = dp[i - 1] + cost[i - 1];
            int jumpTwoStep = dp[i - 2] + cost[i - 2];
            dp[i] = Math.min(jumpOneStep, jumpTwoStep);
        }
        return dp[n];
    }
}