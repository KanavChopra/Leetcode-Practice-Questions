// Tabulation DP

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        // I can reach the top by either coming from (n - 1)th step
        // or (n - 2)th step. So we have to return min of that.
        return min(dp[n - 1], dp[n - 2]);
    }
};