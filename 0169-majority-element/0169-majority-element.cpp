class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[pos]) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                pos = i;
                count = 1;
            }
        } 
        count = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == nums[pos]) {
                count++;
            }
        }
        if (count > n / 2) {
            return nums[pos];
        } else {
            return -1;
        }
    }
};