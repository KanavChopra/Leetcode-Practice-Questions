class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx = 0;
        unordered_set<int> hashSet(nums.begin(), nums.end());
        for (auto& num : nums) {
            int previousConsecutiveElement = num - 1;
            if (!hashSet.count(previousConsecutiveElement)) {
                int currElement = num;
                int currLength = 1;
                while (hashSet.count(currElement + 1)) {
                    currLength++;
                    currElement += 1;
                }
                mx = max(mx, currLength);
            }
        }
        return mx;
    }
};