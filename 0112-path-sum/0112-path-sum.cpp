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
    bool hasPathSum(TreeNode* node, int target) {
        if (!node) return false;

        target -= node->val;

        if (node->left == nullptr && node->right == nullptr) {
            if (target == 0) {
                return true;
            } else {
                return false;
            }
        }

        return hasPathSum(node->left, target) || hasPathSum(node->right, target);
    }
};