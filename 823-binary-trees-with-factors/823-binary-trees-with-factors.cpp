class Solution {
    const int mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> mp;
        mp[arr[0]] = 1;
        for (int i = 1; i < arr.size(); ++i) {
            long long count = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 && mp.find(arr[i] / arr[j]) != mp.end()) {
                    count += mp[arr[j]] * mp[arr[i] / arr[j]];
                    count %= mod;
                }
            }
            mp[arr[i]] = count;
        }
        int cnt = 0;
        for (const auto& key : mp) {
            cnt += key.second;
            cnt %= mod;
        }
        return cnt % mod;
    }
};