//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int n, vector<int> &a) {
        vector<int> pref(n, 0);
        pref[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + a[i];
        }
        vector<int> suff(n, 0);
        suff[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suff[i] = suff[i + 1] + a[i];
        }
        for (int i = 0; i < n; ++i) {
            if (pref[i] == suff[i]) {
                return i + 1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends