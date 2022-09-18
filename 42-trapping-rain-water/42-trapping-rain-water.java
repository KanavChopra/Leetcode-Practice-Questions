class Solution {
    public int trap(int[] height) {
        int ans = 0;
        int n = height.length;
        if (n < 3) {
            return 0;
        }
        
        int left[] = new int[n];
        int right [] = new int[n];
        
        left[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left[i] = Math.max(left[i - 1], height[i]);
        }
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = Math.max(right[i + 1], height[i]);
        }
        
        // don't consider the first and last places
        for (int i = 1; i < n - 1; ++i) {
            ans += Math.min(left[i], right[i]) - height[i];
        }
        return ans;
    }
}