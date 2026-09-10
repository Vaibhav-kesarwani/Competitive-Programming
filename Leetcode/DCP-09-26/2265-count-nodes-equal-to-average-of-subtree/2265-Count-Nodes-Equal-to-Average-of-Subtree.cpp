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
    int ans = 0;
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [ls, lc] = dfs(node->left);
        auto [rs, rc] = dfs(node->right);
        int sum = ls + rs + node->val;
        int cnt = lc + rc + 1;
        if (sum / cnt == node->val) ans++;
        return {sum, cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};