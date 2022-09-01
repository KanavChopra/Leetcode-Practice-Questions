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
    int goodNodes(TreeNode* root, int val = INT_MIN) {
    return root == nullptr ? 0 : (val <= root->val) 
            + goodNodes(root -> left, max(root -> val, val))
                + goodNodes(root -> right, max(root -> val, val));
    }
};


// https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/1408637/C%2B%2B-or-Preorder-or-Logic-Explained-Clearly-or-TC%3A-O(N)-or-SC%3A-O(N)

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/2512547/C%2B%2B-or-Python-or-C97-DFSDetailed-graph-explantion-or-Beginner-friendly-or-Easy-to-understand-_