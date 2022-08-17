class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for (auto& word : words) {
            string ans = "";
            for (auto& ch : word) 
                ans += v[ch - 'a'];
            s.insert(ans);
        }
        return s.size();
    }
};