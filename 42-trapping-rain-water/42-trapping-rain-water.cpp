class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        
        int n = height.size();
        int waterTrapped = 0;
        
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i - 1], height[i]);
        }
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], height[i]);
        }
        
        // ignore the first and last bar
        for (int i = 1; i < n - 1; ++i) {
            waterTrapped += min(left[i], right[i]) - height[i];
        }
        return waterTrapped;
    }
};