//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long height[], int n) {
        vector<long long> lessFromLeft(n); // each i contains index of the first bar in the left that is smaller than the current bar
        vector<long long> lessFromRight(n); // each i contains index of the first bar in the right that is smaller than the current bar
        
        lessFromLeft[0] = -1;
        lessFromRight[n - 1] = n;
        
        for (int i = 0; i < n; ++i) {
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
        long long maxArea = LONG_MIN;
        for (int i = 0; i < n; ++i) {
            maxArea = max(maxArea, height[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
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