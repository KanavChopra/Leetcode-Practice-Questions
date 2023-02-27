class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxProduct = 1;
        int minProduct = 1;
        for (const auto &num : nums) {
            int temp = max({num, num * maxProduct, num * minProduct});
            minProduct = min({num, num * maxProduct, num * minProduct});
            maxProduct = temp;
            res = max(res, maxProduct);
        }
        return res;
    }
};