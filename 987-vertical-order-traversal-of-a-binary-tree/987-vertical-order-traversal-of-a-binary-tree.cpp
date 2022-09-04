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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            int n = q.size();
            multiset<pair<int, int>> ms;
            for (int i = 0; i < n; ++i) {
                auto front = q.front();
                q.pop();
                ms.insert({front.first, front.second -> val});
                if (front.second -> left) {
                    q.push({front.first - 1, front.second -> left});
                }
                if (front.second -> right) {
                    q.push({front.first + 1, front.second -> right});
                }
            }
            for (auto &val : ms) {
                mp[val.first].push_back(val.second);
            }
        }
        vector<vector<int>> res;
        for (auto [key, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};