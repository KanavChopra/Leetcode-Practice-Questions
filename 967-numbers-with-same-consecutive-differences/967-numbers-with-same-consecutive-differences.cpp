class Solution {
public:
    void dfs(int num, int n, int k, vector<int> &res) {
        if (n == 0) {
            res.push_back(num);
        } else {
            int digit = num % 10;
            if (digit + k <= 9) {
                dfs(num * 10 + digit + k, n - 1, k, res);
            }
            if (k != 0 && digit >= k) {
                dfs(num * 10 + digit - k, n - 1, k, res);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        if (n == 1) {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        vector<int> res;
        for (int num = 1; num <= 9; ++num) {
            dfs(num, n - 1, k, res);
        }
        return res;
    }
};