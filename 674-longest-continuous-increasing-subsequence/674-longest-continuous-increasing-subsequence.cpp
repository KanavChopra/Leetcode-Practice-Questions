class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cmax = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                cmax = max(cmax, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return cmax;
    }
};