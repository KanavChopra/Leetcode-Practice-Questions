/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, int dist, int level, map<int, vector<pair<int, int>>> &mp) {
        if (!root) {
            return;
        }
        mp[dist].push_back({level, root -> val});
        dfs(root -> left, dist - 1, level + 1, mp);
        dfs(root -> right, dist + 1, level + 1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>> mp;
        dfs(root, 0, 0, mp);
        for (auto [key, v] : mp) {
            sort(v.begin(), v.end());
            vector<int> tmp;
            for (auto &val : v) {
                tmp.push_back(val.second);
            }
            res.push_back(tmp);
        }
        return res;
    }
};