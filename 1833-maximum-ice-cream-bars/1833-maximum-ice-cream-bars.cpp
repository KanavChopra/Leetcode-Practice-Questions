class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &price : costs) {
            pq.push(price);
        }
        int cnt = 0;
        while (!pq.empty() && pq.top() <= coins) {
            coins -= pq.top();
            pq.pop();
            ++cnt;
        }
        return cnt;
    }
};