// Approach:
// https://leetcode.com/problems/minimum-cost-for-tickets/discuss/762493/C%2B%2B-DP-Solution-w-Detailed-Explanation

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(begin(days), end(days));
        // dp[i] means upto i-th day what is the minimum cost of buying ticket
        int dp[366] = {};
        // dp[0] or day 0 represents day before any trip. so we shouldn't try
        // to minimize it. so we set it to 0
        dp[0] = 0;
        for (int i = 1; i < 366; ++i) {
            if (travel.count(i) == false) {
                // no need to buy ticket if it is not a travel ticket
                dp[i] = dp[i - 1];
            } else {
                // see approach for explanation
                dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2] });
            }
        }
        return dp[365];
    }
};