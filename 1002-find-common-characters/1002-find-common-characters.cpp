class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // This code is used when we only want to show unique characters
        // vector<string> result;
        // vector<char> primary(26, true); // global array where common chars in all strings are stored
        // for (auto& word : words) {
        //     vector<char> secondary(26, false); // tmp array to store which chars are common in current string
        //     for (auto& ch : word) {
        //         if (primary[ch - 'a']) {
        //             secondary[ch - 'a'] = true;
        //         }
        //     }
        //     primary.assign(secondary.begin(), secondary.end());
        // }
        // for (int i = 0; i < 26; ++i) {
        //     if (primary[i]) {
        //         result.push_back(string(1, i + 'a'));
        //     }
        // }
        // return result;
        
        vector<string> result;
        vector<int> primary(26, INT_MAX);
        for (auto& word : words) {
            vector<int> secondary(26, 0);
            for (auto& ch : word) {
                ++secondary[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                primary[i] = min(primary[i], secondary[i]);
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < primary[i]; ++j) {
                result.push_back(string(1, i + 'a'));
            }
        }
        return result;
    }
};