class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (auto &ch : magazine) {
            mp[ch]++;
        }
        for (auto &ch : ransomNote) {
            if (!mp.count(ch) || mp[ch] <= 0) {
                return false;
            }
            mp[ch] -= 1;
        }
        return true;
    }
};