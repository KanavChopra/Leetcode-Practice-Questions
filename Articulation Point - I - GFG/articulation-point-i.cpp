//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited, vector<int>& time, vector<int>& low, int& timer, set<int>& tmp) {
        int count = 0;
        
        visited[node] = 1;
        time[node] = low[node] = timer++;
        
        for (auto &nbr : adj[node]) {
            if (nbr == parent) {
                continue;
            } else if (!visited[nbr]) {
                ++count;
                dfs(nbr, node, adj, visited, time, low, timer, tmp);
                low[node] = min(low[node], low[nbr]);
                if (parent == -1) {
                    if (count >= 2) {
                        tmp.insert(node);
                    }
                } else {
                    if (low[nbr] >= time[node]) {
                        tmp.insert(node);
                    }
                }
            } else {
                low[node] = min(low[node], time[nbr]);
            }
        }
    }
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        vector<int> visited(v, 0);
        vector<int> time(v, -1);
        vector<int> low(v, -1);
        set<int> tmp;
        int timer = 0;
        
        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, time, low, timer, tmp);
            }
        }
        vector<int> ans(tmp.begin(), tmp.end());
        if (ans.size() == 0) {
            return {-1};
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends