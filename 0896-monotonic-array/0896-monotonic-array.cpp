class Solution {
    bool isIncreasing(vector<int>& nums) {
        bool increasing = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    bool isDecreasing(vector<int>& nums) {
        bool decreasing = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = isIncreasing(nums);
        bool decreasing = isDecreasing(nums);
        return increasing || decreasing;
    }
};