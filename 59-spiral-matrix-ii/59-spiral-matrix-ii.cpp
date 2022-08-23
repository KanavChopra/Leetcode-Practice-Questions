class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;
        int direction = 0;
        while (left <= right && top <= bottom) {
            switch (direction % 4) {
                case 0:
                    for (int i = left; i <= right; ++i) {
                        ans[top][i] = num++;
                    }
                    top++;
                    break;
                case 1:
                    for (int i = top; i <= bottom; ++i) {
                        ans[i][right] = num++;
                    }
                    right--;
                    break;
                case 2:
                    if (top <= bottom) {
                        for (int i = right; i >= left; --i) {
                            ans[bottom][i] = num++;
                        }
                        bottom--;
                    }
                    break;
                case 3:
                    if (left <= right) {
                        for (int i = bottom; i >= top; --i) {
                            ans[i][left] = num++;
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