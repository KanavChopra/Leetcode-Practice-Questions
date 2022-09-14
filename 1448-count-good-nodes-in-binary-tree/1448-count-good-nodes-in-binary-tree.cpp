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
    // int goodNodes(TreeNode* root, int mx = INT_MIN) {
    //     // DFS
    //     if (!root) {
    //         return 0;
    //     }
    //     int cnt = 0;
    //     if (root -> val >= mx) {
    //         ++cnt;
    //         mx = max(mx, root -> val);
    //     }
    //     cnt += goodNodes(root -> left, mx);
    //     cnt += goodNodes(root -> right, mx);
    //     return cnt;
    // }
    
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        while (!q.empty()) {
            auto [node, mx] = q.front();
            q.pop();
            res += (node -> val >= mx);
            if (node -> left) {
                q.push({node -> left, max(mx, node -> val)});
            }
            if (node -> right) {
                q.push({node -> right, max(mx, node -> val)});
            }
        }
        return res;
    }
};