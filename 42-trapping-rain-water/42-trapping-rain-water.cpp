class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        
        int n = height.size();
        stack<int> st;
        int waterTrapped = 0;
        
        for (int curr = 0; curr < n; ++curr) {
            // remove bars from the stack until
            // st.top is smaller than curr which 
            // means curr is right max for st.top
            while (!st.empty() && height[st.top()] < height[curr]) {
                int bar = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int width = curr - st.top() - 1;
                waterTrapped += (width * (min(height[curr], height[st.top()]) - height[bar]));
            }
            // if the stack is either empty or
            // height of the current bar is less than
            // or equal to the top bar of stack
            st.push(curr);
        }
        return waterTrapped;
    }
};