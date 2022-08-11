class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<long long, long long> mp;
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            count += i - mp[nums[i] - i];
            ++mp[nums[i] - i];
        }
        return count;
    }
};