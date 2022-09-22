class Solution {
public:
    string reverseStr(string s, int k) {
        int start = 0;
        int end = min((int)s.length(), k);
        while (start < s.length()) {
            reverse(s.begin() + start, s.begin() + end);
            start += 2 * k;
            end = min((int)s.length(), start + k);
        }
        return s;
    }
};