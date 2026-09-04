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
    vector<int> preorder(TreeNode* root, vector<int>& vtr) {
        if (root == nullptr) {
            return {};
        }

        vtr.push_back(root->val);
        preorder(root->left, vtr);
        preorder(root->right, vtr);

        return vtr;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        return preorder(root, ans);
    }
};