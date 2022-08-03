class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi = m - 1;
        while (lo < n && hi >= 0) {
            if (matrix[lo][hi] > target) {
                hi--;
            } else if (matrix[lo][hi] < target) {
                lo++;
            } else {
                return true;
            }
        }
        return false;
    }
};