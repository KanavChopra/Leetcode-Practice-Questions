class Solution {
public:
    vector<vector<int>> generate(int N) {
        vector<vector<int> > output(N);
        for (int i = 0; i < N; ++i) {
            output[i].resize(i + 1); // each i-th row has i + 1 columns
            output[i][0] = 1;
            output[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                output[i][j] = output[i - 1][j - 1] + output[i - 1][j];
            }
        }
        return output;
    }
};