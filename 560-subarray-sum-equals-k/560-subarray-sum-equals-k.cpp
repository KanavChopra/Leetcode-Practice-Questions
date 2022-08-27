class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            sum += nums[i];
            if (hashMap.count(sum - k)) 
                count += hashMap[sum - k];
            hashMap[sum] += 1;
        }
        return count;
    }
};