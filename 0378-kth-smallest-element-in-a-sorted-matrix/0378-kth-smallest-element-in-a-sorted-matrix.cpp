class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n - 1][m - 1];
        int desired = k - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            int count = 0;
            for (int i = 0; i < n; ++i) {
                count += upper_bound(begin(matrix[i]), end(matrix[i]), mid) - begin(matrix[i]);
            }
            if (count <= desired) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};