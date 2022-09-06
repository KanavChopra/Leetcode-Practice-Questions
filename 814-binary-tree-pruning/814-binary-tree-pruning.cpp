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


// returning NULL simply means that you remove the reference to the object 
// that root was pointing to [a TreeNode in this case], and if there is no 
// reference to an object it will automatically be removed by the garbage collector, 
// and memory will be released.

class Solution {
public:
    TreeNode* dfs(TreeNode *root) {
        if (!root) {
            return NULL;
        }
        root -> left = dfs(root -> left);
        root -> right = dfs(root -> right);
        if (root -> left == NULL && root -> right == NULL && root -> val == 0) {
            return NULL;
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
};