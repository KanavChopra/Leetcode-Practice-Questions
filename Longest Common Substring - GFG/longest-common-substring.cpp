//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLen = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                char c1 = s1[i - 1];
                char c2 = s2[j - 1];
                if (c1 != c2) {
                    continue;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends