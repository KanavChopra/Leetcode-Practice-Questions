// Approach:
// https://leetcode.com/problems/minimum-cost-for-tickets/discuss/227321/Top-down-DP-Logical-Thinking

class Solution {
public:
    int getNextDayIndex(int dayIndex, vector<int>& days, int duration) {
        int endDay = days[dayIndex] + duration - 1;
        int nextDay = dayIndex;
        while (nextDay < days.size() && days[nextDay] <= endDay) {
            nextDay++;
        }
        return nextDay;
    }
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (i >= days.size()) {
            return 0;
        }
        if (dp[i] != INT_MAX) {
            return dp[i];
        }
        int totalCostDay = costs[0] + solve(getNextDayIndex(i, days, 1), days, costs, dp);
        int totalCostWeek = costs[1] + solve(getNextDayIndex(i, days, 7), days, costs, dp);
        int totalCostMonth = costs[2] + solve(getNextDayIndex(i, days, 30), days, costs, dp);
        return dp[i] = min({totalCostDay, totalCostWeek, totalCostMonth});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, INT_MAX);
        return solve(0, days, costs, dp);
    }
};