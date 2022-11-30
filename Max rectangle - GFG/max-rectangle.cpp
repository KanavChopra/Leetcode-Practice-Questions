//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
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
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        vector<int> heights(m);
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    heights[j] = 0;
                } else if (matrix[i][j] == 1) {
                    heights[j] += 1;
                }
            }
            maxArea = max(maxArea, largestRectangleHistogram(heights));
        }
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends