class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto& num : arr) {
            mp[num]++;
        }
        priority_queue<int> pq;
        for (auto& iter : mp) {
            pq.push(iter.second);
        }
        int count = 0;
        int size = 0;
        while (2 * count < arr.size()) {
            count += pq.top();
            pq.pop();
            size++;
        }
        return size;
    }
};