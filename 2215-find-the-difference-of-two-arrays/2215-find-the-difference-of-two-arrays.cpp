class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> output;
        unordered_set<int> set1(nums2.begin(), nums2.end());
        unordered_set<int> set2(nums1.begin(), nums1.end());
        vector<int> tmp;
        for (auto& val : set2) {
            if (!set1.count(val)) {
                tmp.push_back(val);
            }
        }
        output.push_back(tmp);
        tmp.clear();
        for (auto& val : set1) {
            if (!set2.count(val)) {
                tmp.push_back(val);
            }
        }
        output.push_back(tmp);
        return output;
    }
};