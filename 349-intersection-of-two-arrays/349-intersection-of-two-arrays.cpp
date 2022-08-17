class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> output;
        for (auto& val : nums2) {
            if (s.count(val)) {
                output.push_back(val);
                s.erase(val);
            }
        }
        return output;
    }
};