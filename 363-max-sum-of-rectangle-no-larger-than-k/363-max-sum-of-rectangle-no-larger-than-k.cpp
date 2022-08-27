class Solution {
private:
    int kadanesAlgorithm(vector<int>& a, int k) {
        int maxSum = INT_MIN;
        int currSum = 0;
        int n = a.size();
        set<int> s;
        s.insert(0);
        for (int i = 0; i < n; ++i) {
            currSum += a[i];
            auto iterator = s.lower_bound(currSum - k);
            if (iterator != s.end()) {
                maxSum = max(maxSum, currSum - *iterator);
            }
            s.insert(currSum);
        }
       return maxSum;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int maxSum = INT_MIN;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int left = 0; left < cols; ++left) {
            vector<int> a(rows, 0);
            for (int right = left; right < cols; ++right) {
                for (int i = 0; i < rows; ++i) {
                    a[i] += matrix[i][right];
                }
                maxSum = max(maxSum, kadanesAlgorithm(a, k));
            }
        }
        return maxSum;
    }
};