// N-th row of pascal triangle is Nc0, Nc1, Nc2, ....., Ncn;
// Now Ncr = Ncr - 1 * (N - r + 1) / r

class Solution {
public:
    vector<int> getRow(int N) {
        vector<int> row;
        int prev = 1;
        row.push_back(prev);
        for (int i = 1; i <= N; ++i) {
            int curr = ((long) prev * (long)(N - i + 1)) / i;
            row.push_back(curr);
            prev = curr;
        }
        return row;
    }
};