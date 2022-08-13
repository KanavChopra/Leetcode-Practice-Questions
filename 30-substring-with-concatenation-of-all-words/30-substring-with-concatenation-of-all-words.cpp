class Solution {
    unordered_map<string, int> mp;
    unordered_map<string, int> tmp;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int k = words.size();
        int wordLength = words[0].length();
        int subStringSize = wordLength * k;
        for (string word : words) {
            mp[word]++;
        }
        vector<int> ans;
        for (int i = 0; i < n - subStringSize + 1; i++) {
            // Iterate the current window of length subStringSize
            // over the range [i, i + subStringSize] and extract
            // the substring of length wordLength and store it's 
            // frequency.
            for (int j = i; j < i + subStringSize; j += wordLength) {
                string str = s.substr(j, wordLength);
                 // Now, check if the frequency of each string
                // in map mp is the same as the frequency in
                // map tmp. This ensure that the current
                // window is of the same concatenation of
                // the strings in the array words[]
                if (mp.count(str)) {
                    tmp[str]++;
                } else {
                    break;
                }
            }
            if (tmp == mp) {
                ans.push_back(i);
            }
            // clear tmp for next iteration because we
            // need to find again for furhter indexes
            tmp.clear();
        }
        return ans;
    }
};