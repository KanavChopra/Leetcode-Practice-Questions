class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int count1 = 0;
        int count2 = 0;
        int num1 = -1;
        int num2 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == num1) {
                ++count1;
            } else if (nums[i] == num2) {
                ++count2;
            } else if (count1 == 0) {
                count1 = 1;
                num1 = nums[i];
            } else if (count2 == 0) {
                count2 = 1;
                num2 = nums[i];
            } else {
                --count1;
                --count2;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == num1) {
                ++count1;
            } else if (nums[i] == num2) {
                ++count2;
            }
        }
        vector<int> res;
        if (count1 > n / 3) {
            res.push_back(num1);
        }
        if (count2 > n / 3) {
            res.push_back(num2);
        }
        return res;
    }
};