class Solution {
public:
    int firstOccurence(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    int lastOccurence(vector<int>& nums,int target) {
        int n = nums.size();
        int ans = -1;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans = mid;
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> output(2, -1);
        if (nums.empty()) {
            return output;
        }
        output[0] = firstOccurence(nums, target);
        output[1] = lastOccurence(nums, target);
        return output;
    }
};