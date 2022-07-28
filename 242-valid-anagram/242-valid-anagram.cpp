class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashMap;
        for (auto& ch : s) {
            hashMap[ch]++;
        }
        for (auto& ch : t) {
            hashMap[ch]--;
            if (hashMap[ch] == 0) {
                hashMap.erase(ch);
            }
        }
        return (hashMap.empty() ? true : false);
    }
};