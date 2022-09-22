class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        
        string res = "";
        while (ss >> word) {
            reverse(word.begin(), word.end());
            res += word + " ";
        }
        res = res.substr(0, s.length());
        return res;
    }
};