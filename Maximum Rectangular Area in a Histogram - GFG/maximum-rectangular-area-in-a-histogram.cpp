//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long height[], int n) {
        stack<long long> stk;
        long long maxArea = LONG_MIN;
        for (int i = 0; i <= n; ++i) {
            long long currHeight = i == n ? 0 : height[i];
            while (!stk.empty() && currHeight < height[stk.top()]) {
                long long top = stk.top();
                stk.pop();
                long long width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, height[top] * width);
            }
            stk.push(i);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends