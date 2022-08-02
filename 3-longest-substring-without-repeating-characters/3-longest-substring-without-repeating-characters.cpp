class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashSet;
        int n = s.length();
        int start = 0;
        int maxLength = 0;
        for (int end = 0; end < n; ++end) {
            while (hashSet.find(s[end]) != hashSet.end()) {
                hashSet.erase(s[start]);
                start++;
            }
            hashSet.insert(s[end]);
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};