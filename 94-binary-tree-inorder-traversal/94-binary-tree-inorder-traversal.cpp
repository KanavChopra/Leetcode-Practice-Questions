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
    void dfs(TreeNode* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        dfs(root -> left, res);
        res.push_back(root -> val);
        dfs(root -> right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // Recursive Solution
        vector<int> res;
        dfs(root, res);
        return res;
        
        // Iterative Solution
        // stack<TreeNode>* s;
        // vector<int> res;
        // TreeNode* current = root;
        // while(true) {
        //     if (current != NULL) {
        //         s.push(current);
        //         current = current -> left;
        //     } else {
        //         current = s.top();
        //         s.pop();
        //         res.push_back(current);
        //         current = current -> right;
        //     }
        // }
        // return res;
    }
};