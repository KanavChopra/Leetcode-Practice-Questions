class Solution {
public:
    int largestRectangleHistogram(vector<int> &heights) {
        int n = heights.size();
        
        stack<int> stk;
        int maxArea = 0;
        for (int i = 0; i <= n; ++i) {
            int currHeight = i == n ? 0 : heights[i];
            while (!stk.empty() && currHeight < heights[stk.top()]) {
                int top = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, heights[top] * width);
            }
            stk.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> heights(m);
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else if (matrix[i][j] == '1') {
                    heights[j] += 1;
                }
            }
            maxArea = max(maxArea, largestRectangleHistogram(heights));
        }
        return maxArea;
    }
};