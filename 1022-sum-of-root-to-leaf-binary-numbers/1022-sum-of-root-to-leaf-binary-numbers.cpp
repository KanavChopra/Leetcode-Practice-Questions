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
    int sumRootToLeaf(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        int curr = 0;
        while (root) {
            if (!root -> left) {
                curr = curr * 2 + root -> val;
                if (!root -> right) {
                    sum += curr;
                }
                root = root -> right;
            } else {
                TreeNode *predecessor = root -> left;
                int depth = 1;
                while (predecessor -> right && predecessor -> right != root) {
                    predecessor = predecessor -> right;
                    ++depth;
                }
                if (!predecessor -> right) {
                    predecessor -> right = root;
                    curr = curr * 2 + root -> val;
                    root = root -> left;
                } else {
                    predecessor -> right = NULL;
                    if (!predecessor -> left) {
                        sum += curr;
                    }
                    curr /= pow(2, depth);
                    root = root -> right;
                }
            }
        }
        return sum;
    }
};