class Solution {
    bool dfs(vector<vector<int>> &g, vector<int> &visited, vector<int> &safe, int node) {
        visited[node] = 1;
        for (int i = 0; i < g[node].size(); ++i) {
            int nbr = g[node][i];
            if (safe[nbr]) {
                continue;
            }
            if (visited[nbr]) {
                return false;
            }
            if (!dfs(g, visited, safe, nbr)) {
                return false;
            }
        }
        safe[node] = 1;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<int> visited(n, 0);
        vector<int> safe(n, 0);
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (dfs(g, visited, safe, i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};