class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        unordered_map<char, int> mp;
        for (const auto &ch : t) {
            ++mp[ch];
        }
        
        int desiredCharacters = mp.size();
        int start = 0;
        int count = 0;
        int startIndex = -1;
        int minLength = INT_MAX;
        unordered_map<char, int> window;
        for (int end = 0; end < n; ++end) {
            window[s[end]]++;
            if (mp.count(s[end]) && window[s[end]] == mp[s[end]]) {
                ++count;
            }
            while (count == desiredCharacters) {
                if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    startIndex = start;
                }
                --window[s[start]];
                if (mp.count(s[start]) && window[s[start]] < mp[s[start]]) {
                    --count;
                }
                ++start;
            }
        }
        return (startIndex == -1 ? "" : s.substr(startIndex, minLength));
    }
};