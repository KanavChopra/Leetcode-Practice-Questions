class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[n - 1];
        for (int i = 0; i < n - 2; ++i) {
            int start = i + 1;
            int end = n - 1;
            while (start < end) {
                int currSum = nums[i] + nums[start] + nums[end];
                currSum > target ? end-- : start++;
                if (abs(currSum - target) < abs(closestSum - target)) {
                    closestSum = currSum;
                }
            }
        }
        return closestSum;
    }
};