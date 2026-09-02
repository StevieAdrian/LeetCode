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
    int traverse(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } 

        int left = traverse(root->left);
        int right = traverse(root->right);

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int hl = 0, hr = 0;

        if (root != nullptr) {
            hl = traverse(root->left);
            hr = traverse(root->right);
        }

        cout << hl << " " << hr << endl;

        if (abs(hl - hr) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};