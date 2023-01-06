class Solution {
public:
    void solve(int i, vector<int> &candidates, int n, int target, vector<int> &tmp, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        for (int k = i; k < n; ++k) {
            if (k != i && candidates[k] == candidates[k - 1]) {
                continue;
            }
            if (candidates[k] > target) {
                break;
            }
            tmp.push_back(candidates[k]);
            solve(k + 1, candidates, n, target - candidates[k], tmp, res);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> tmp;
        sort(begin(candidates), end(candidates));
        solve(0, candidates, n, target, tmp, res);
        return res;
    }
};