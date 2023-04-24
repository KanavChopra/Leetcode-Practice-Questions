class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (const auto &stone : stones) {
            pq.push(stone);
        }
        while (pq.size() != 1) {
            int heaviest = pq.top();
            pq.pop();
            int secondHeaviest = pq.top();
            pq.pop();
            pq.push(heaviest - secondHeaviest);
        }
        return pq.top();
    }
};