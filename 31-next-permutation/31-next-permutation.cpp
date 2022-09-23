class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k;
        int pivot;
        for (k = n - 2; k >= 0; --k) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        } else {
            for (int j = n - 1; j >= 0; --j) {
                if (nums[j] > nums[k]) {
                    swap(nums[k], nums[j]);
                    break;
                }
            }
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};