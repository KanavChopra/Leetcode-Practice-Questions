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
private:
    int ans = 0;
public:
    void dfs(TreeNode *root, vector<int> &freq) {
        if (!root) {
            return;
        }
        freq[root -> val]++;
        if (!root -> left && !root -> right) {
            if (isPalindromePermutation(freq)) {
                ans++;
            }
        }
        dfs(root -> left, freq);
        dfs(root -> right, freq);
        freq[root -> val]--;
    }
    bool isPalindromePermutation(vector<int> &freq) {
        bool flag = false;
        for (auto &val : freq) {
            if (val & 1) {
                if (flag) {
                    return false;
                }
                flag = true;
            }
        }
        return true;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0);
        dfs(root, freq);
        return ans;
    }
};