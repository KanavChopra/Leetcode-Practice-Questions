class Solution {
public:
    void letterCombinations(string digits, vector<string> &res, vector<string> &options) {
        if (digits.empty()) {
            res.push_back("");
            return;
        }
        
        int firstDigit = digits[0] - '0';
        vector<string> output;
        
        letterCombinations(digits.substr(1), output, options);
        string op = options[firstDigit];
        for (int i = 0; i < output.size(); ++i) {
            for (int j = 0; j < op.size(); ++j) {
                res.push_back(op[j] + output[i]);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> options{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        letterCombinations(digits, res, options);
        return res;
    }
};