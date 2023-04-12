//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    void dfs(vector<int> adj[], int node, vector<int> &visited, stack<int> &stk) {
        visited[node] = 1;
        for (auto &nbr : adj[node]) {
            if (!visited[nbr]) {
                dfs(adj, nbr, visited, stk);
            }
        }
        stk.push(node);
    }
	public:
	vector<int> topoSort(int n, vector<int> adj[]) {
	    vector<int> res;
	    vector<int> visited(n, 0);
	    stack<int> stk;
	    for (int i = 0; i < n; ++i) {
	        if (!visited[i]) {
	            dfs(adj, i, visited, stk);
	        }
	    }
	    while (!stk.empty()) {
	        int top = stk.top();
	        stk.pop();
	        res.push_back(top);
	    }
	    return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends