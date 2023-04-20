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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int mx = 0;
        while (!q.empty()) {
            int size = q.size();
            int leftMostNodeIndex = q.front().second;
            int rightMostNodeIndex = q.back().second;
            mx = max(mx, rightMostNodeIndex - leftMostNodeIndex + 1);
            for (int i = 0; i < size; ++i) {
                pair<TreeNode*, int> front = q.front();
                q.pop();
                TreeNode* node = front.first;
                int parentIndex = front.second;
                if (node -> left) {
                    q.push({node -> left, (long long) 2 * parentIndex + 1});
                }
                if (node -> right) {
                    q.push({node -> right, (long long) 2 * parentIndex + 2});
                }
            }
        }
        return mx;
    }
};