class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        
        vector<int> lessFromLeft(n); // index of the first bar in the left that is lower than the current
        vector<int> lessFromRight(n); // index of the first bar in the right that is lower than the current
        
        lessFromLeft[0] = -1;
        lessFromRight[n - 1] = n;
        for (int i = 1; i < n; ++i) {
            int p = i - 1;
            while (p >= 0 && height[p] >= height[i]) {
                p = lessFromLeft[p];
            }
            lessFromLeft[i] = p;
        }
        for (int i = n - 2; i >= 0; --i) {
            int p = i + 1;
            while (p < n && height[p] >= height[i]) {
                p = lessFromRight[p];
            }
            lessFromRight[i] = p;
        }
        int maxArea = INT_MIN;
        for (int i = 0; i < n; ++i) {
            maxArea = max(maxArea, height[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
        }
        return maxArea;
    }
};