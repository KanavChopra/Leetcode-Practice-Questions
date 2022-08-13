// 1. The only thing to understand in this code is the condition 
//    if (hashMap.count(c) && window[c] == hashMap[c]) {
//          count++;
//    }
// 2. Why window[c] == hashMap[c] and not window[c] <= hashMap[c] ?
// 3. Consider t = abbc then hashMap is a : 1, b : 2, c : 1
//    Now when we are acquiring the characters and we get to b and its frequency is 1 this means
//    we have not reached to a point where we have 2 b's in the substring because we need to increase
//    the count when we have 2 b's in the substring so that's why the condition.
// 4. Means mujhe meri substring mein 1 a chaahiye, 2 b chaahiye and 1 c chaahiye but abhi tk mere
//    paas string s mein iterate krete hue mujhe 1 - a, 1 - b and 1 - c mile hai in a substring so a ka
//    count required ke baraabar hai so count++, similarly for c count++ but abhi required no of b's nhi
//    mile hai ia lie b  maine count++ nhi kia, tbhi krunga jb required no of b's mil jaaenge. So jb 
//    mujhe saare characters mill jaaenge with ek substring mein with their required frequencies then 
//    we can say the we required 1 - a, 2 - b, 1 - c in to exist in a substring and we have found a
//    substring corresponding to that and we just need to contract the substring taking care the 
//    freq's dont change.
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char, int> hashMap;
        for (const auto &i : t) {
            hashMap[i]++;
        }
        int desired = hashMap.size();
        int count = 0;
        int start = 0;
        int startIndex = -1;
        int minLength = INT_MAX;
        unordered_map<char, int> window;
        for (int end = 0; end < n; ++end) {
            char c = s[end];
            window[c]++;
            if (hashMap.count(c) && window[c] == hashMap[c]) {
                count++;
            }
            // try to contract the window till the point it ceases to be desirable
            while (count == desired) {
                // save the smallest window until now
                if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    startIndex = start;
                }
                // start is no longer part of the window
                window[s[start]]--;
                if (hashMap.count(s[start]) && window[s[start]] < hashMap[s[start]]) {
                    count--;
                }
                start++;
            }
        }
        return (startIndex == -1 ? "" : s.substr(startIndex, minLength));
    }
};