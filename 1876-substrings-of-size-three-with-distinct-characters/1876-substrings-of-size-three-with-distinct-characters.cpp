class Solution {
public:
    bool checkString(string s) {
        unordered_map<char, int> mp;
        for (auto& ch : s) {
            mp[ch]++;
        }
        for (auto& key : mp) {
            if(key.second > 1) {
                return false;
            }
        }
        return true;
    }
    int countGoodSubstrings(string s) {
        int k = 3;
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            if (checkString(s.substr(i, k))) {
                cnt++;
            }
        }
        return cnt;
    }
};