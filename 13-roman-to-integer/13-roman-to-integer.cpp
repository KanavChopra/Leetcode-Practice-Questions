class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashMap;
        hashMap['I'] = 1;
        hashMap['V'] = 5;
        hashMap['X'] = 10;
        hashMap['L'] = 50;
        hashMap['C'] = 100;
        hashMap['D'] = 500;
        hashMap['M'] = 1000;
        int num = hashMap[s[s.length() - 1]];
        int next = hashMap[s[s.length() - 1]];
        for (int i = (s.length() - 2); i >= 0; --i) {
            num = hashMap[s[i]] < next ? num - hashMap[s[i]] : num + hashMap[s[i]];
            next = hashMap[s[i]];
        }
        return num;
    }
};