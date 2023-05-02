class Solution {
public:
    int arraySign(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (const auto &num : nums) {
            if (num == 0) {
                mp[0]++;
            } else if (num > 0) {
                mp[1]++;
            } else {
                mp[-1]++;
            }
        }
        for (const auto &key : mp) {
            if (mp[0] >= 1) {
                return 0;
            } else {
                if (mp[-1] % 2 == 0) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
        return 0;
    }
};