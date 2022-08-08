// Space Optimized 

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];
        for (int i = 2; i < n; ++i) {
            int curr = min(a, b) + cost[i];
            a = b;
            b = curr;
        }
        return min(a, b);
    }
};