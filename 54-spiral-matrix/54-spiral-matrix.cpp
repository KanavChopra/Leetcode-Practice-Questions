class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int r = matrix.size();
        int c = matrix[0].size();
        int top = 0;
        int bottom = r - 1;
        int left = 0;
        int right = c - 1;
        int direction = 0;
        while (left <= right && top <= bottom) {
            switch (direction % 4) {
                case 0:
                    for (int i = left; i <= right; ++i) {
                        ans.push_back(matrix[top][i]);
                    }
                    top++;
                    break;
                case 1:
                    for (int i = top; i <= bottom; ++i) {
                        ans.push_back(matrix[i][right]);
                    }
                    right--;
                    break;
                case 2:
                    if (top <= bottom) {
                        for (int i = right; i >= left; --i) {
                            ans.push_back(matrix[bottom][i]);
                        }
                        bottom--;
                    }
                    break;
                case 3:
                    if (left <= right) {
                        for (int i = bottom; i >= top; --i) {
                            ans.push_back(matrix[i][left]);
                        }
                        left++;
                    }
                    break;
            }
            direction += 1;
        }
        return ans;
    }
};