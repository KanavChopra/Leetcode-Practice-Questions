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
    vector<int> path;
    vector<vector<int>> res;
    
    void dfs(TreeNode* root, int sum) {
        if (!root) {
            return;
        }
        if (!root -> left && !root -> right && sum == root -> val) {
            path.push_back(root -> val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root -> val);
        dfs(root -> left, sum - root -> val);
        dfs(root -> right, sum - root -> val);
        path.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};