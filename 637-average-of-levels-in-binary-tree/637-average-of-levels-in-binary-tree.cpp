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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> output;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                auto front = q.front();
                q.pop();
                sum += front -> val;
                if (front -> left) {
                    q.push(front -> left);
                }
                if (front -> right) {
                    q.push(front -> right);
                }
            }
            output.push_back(sum / size);
        }
        return output;
    }
};