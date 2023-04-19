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
    int maxPathSum = 0;
    
    int dfs(TreeNode* root, int direction) {
        if (!root) {
            return -1;
        }
        int left = dfs(root -> left, 0);
        int right = dfs(root -> right, 1);
        maxPathSum = max(maxPathSum, 1 + max(left, right));
        return direction ? left + 1 : right + 1;
    }
public:
    int longestZigZag(TreeNode* root) {
        // 0 -> currently in left direction
        // 1 -> currently in right direction
        dfs(root, 0);
        return maxPathSum;
    }
};