class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &num : arr) {
            pq.push({abs(num - x), num});
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};