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
    vector<string> res;
public:
    void dfs(TreeNode *root, string curr) {
        if (!root -> left && !root -> right) {
            res.push_back(curr);
        }
        if (root -> left) {
            dfs(root -> left, curr + "->" + to_string(root -> left -> val));
        }
        if (root -> right) {
            dfs(root -> right, curr + "->" + to_string(root -> right -> val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return res;
        }
        dfs(root, to_string(root -> val));
        return res;
    }
};