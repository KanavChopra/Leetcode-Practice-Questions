class Solution {
    int parent[26];
    
    int find(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        int n = (int) equations.size();
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }
        // == case
        for (auto &str : equations) {
            if (str[1] == '=') {
                parent[find(str[0] - 'a')] = find(str[3] - 'a');
            }
        }
        // != case
        for (auto &str : equations) {
            if (str[1] == '!' && find(str[0] - 'a') == find(str[3] - 'a')) {
                return false;
            }
        }
        return true;
    }
};