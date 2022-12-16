//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DSU {
    public:
    vector<int> parent;
    vector<int> size;
    
    void make_set(int v) {
        for (int i = 0; i < v; ++i) {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int find_set(int v) {
        return (v == parent[v]) ? v : parent[v] = find_set(parent[v]);
    }
    
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
    private:
        bool isValid(int x, int y, int n) {
            return (x >= 0 && x < n && y >= 0 && y < n);
        }
    public:
        int MaxConnection(vector<vector<int>>& grid) {
            int n = (int) grid.size();
            
            DSU dsu;
            dsu.make_set(n * n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1) {
                        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                        for (auto &direction : directions) {
                            int newX = i + direction[0];
                            int newY = j + direction[1];
                            if (isValid(newX, newY, n)) {
                                int curr = (i * n) + j;
                                int adj = (newX * n) + newY;
                                if (grid[newX][newY] == 1) {
                                    dsu.union_sets(curr, adj);
                                }
                            }
                        }
                    }
                }
            }
            int mx = -1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 0) {
                        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                        set<int> components;
                        for (auto &direction : directions) {
                            int newX = i + direction[0];
                            int newY = j + direction[1];
                            if (isValid(newX, newY, n) && grid[newX][newY] == 1) {
                                components.insert(dsu.find_set((newX * n) + newY));
                            }
                        }
                        int size = 0;
                        for (auto &val : components) {
                            size += dsu.size[val];
                        }
                        mx = max(mx, size + 1);
                    }
                }
            }
            return mx == -1 ? n * n : mx;
        }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends