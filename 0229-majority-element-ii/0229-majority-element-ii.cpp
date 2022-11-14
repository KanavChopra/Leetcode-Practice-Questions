class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first = -1;
        int second = -1;
        int count1 = 0;
        int count2 = 0;
        for (auto &val : nums) {
            if (val == first) {
                count1++;
            } else if (val == second) {
                count2++;
            } else if (count1 == 0) {
                first = val;
                count1 = 1;
            } else if (count2 == 0) {
                second = val;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for (auto &val : nums) {
            if (val == first) {
                count1++;
            } else if (val == second) {
                count2++;
            }
        }
        int n = nums.size();
        if (count1 > n / 3) {
            ans.push_back(first);
        }
        if (count2 > n / 3) {
            ans.push_back(second);
        }
        return ans;
    }
};