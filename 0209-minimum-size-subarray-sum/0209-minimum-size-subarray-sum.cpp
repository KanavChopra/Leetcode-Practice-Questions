class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int start = 0;
        int mn = INT_MAX;
        int sum = 0;
        
        for (int end = 0; end < n; ++end) {
            sum += nums[end];
            while (sum >= target && start < n) {
                if (end - start + 1 <= mn) {
                    mn = end - start + 1;
                }
                sum -= nums[start++];
            }
        }
        return mn == INT_MAX ? 0 : mn;
    }
};