class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for (auto &val : nums) {
            mp[val]++;
        }
        int mx = -1;
        int ans = -1;
        for (auto &key : mp) {
            if (!(key.first & 1) && key.second > mx) {
                mx = key.second;
                ans = key.first;
            }
        } 
        return ans;
    }
};