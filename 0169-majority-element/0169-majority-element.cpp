class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int idx = 0;
        for (int i = 1; i < n; ++i) {
            count = (nums[i] == nums[idx]) ? count + 1 : count - 1;
            if (count == 0) {
                count = 1;
                idx = i;
            }
        }
        count = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == nums[idx]) {
                ++count;
            }
        }
        return (count > n / 2) ? nums[idx] : -1;
    }
};