class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int leftProduct = 1;
        int rightProduct = 1;
        int res = nums[0];
        for (int i = 0; i < n; ++i) {
            leftProduct = (leftProduct ? leftProduct : 1);
            rightProduct = (rightProduct ? rightProduct : 1);
            leftProduct *= nums[i];
            rightProduct *= nums[n - i - 1];
            res = max({res, leftProduct, rightProduct});
        }
        return res;
    }
};