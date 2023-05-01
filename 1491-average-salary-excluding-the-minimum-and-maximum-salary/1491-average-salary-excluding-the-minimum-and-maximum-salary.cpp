class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int sum = accumulate(begin(salary), end(salary), 0);
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            mn = min(mn, salary[i]);
            mx = max(mx, salary[i]);
        }
        return (double) (sum - (mn + mx)) / (n - 2);
    }
};