//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int majorityElement(int a[], int size) {
        int count = 1;
        int idx = 0;
        for (int i = 1; i < size; ++i) {
            count = (a[i] == a[idx]) ? count + 1 : count - 1;
            if (count == 0) {
                count = 1;
                idx = i;
            }
        }
        count = 0;
        for (int i = 0; i < size; ++i) {
            if (a[i] == a[idx]) {
                ++count;
            }
        }
        return (count > size / 2) ? a[idx] : -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends