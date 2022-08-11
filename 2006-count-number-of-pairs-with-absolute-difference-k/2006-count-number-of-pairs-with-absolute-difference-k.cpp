class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        for (auto& val : nums) {
            count += mp[val + k] + mp[val - k];
            ++mp[val];
        }
        return count;
    }
};