/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root->left && !root->right) {
            return {root->val};
        }
        int f = 0, num = -1, maxf = 0;
        inorder(res, f, root, num, maxf);
        if (f > maxf) {
            return {num};
        } 
        else if (f == maxf) {
            res.push_back(num);
        }
        return res;
    }

    void inorder(vector<int>& res, int& f, TreeNode* root, int& num,
                 int& maxf) {
        if (!root)
            return;
        inorder(res, f, root->left, num, maxf);
        if (f == 0) {
            f = 1;
            num = root->val;
        } else {
            if (root->val == num) {
                f++;
            } else {
                if (f > maxf) {
                    res.clear();
                    res.push_back(num);
                    maxf = f;
                } 
                else if (f == maxf) {
                    res.push_back(num);
                }
                f = 1;
                num = root->val;
            }
        }
        inorder(res, f, root->right, num, maxf);
    }
};