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
    pair<int, int> dfs(TreeNode* root, int& ctr) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto right = dfs(root->right, ctr);
        auto left = dfs(root->left, ctr);

        int sum = root->val + right.first + left.first;
        int idx = right.second + left.second + 1;

        if (root->val == sum/idx) {
            ctr++;
        }

        return {sum, idx};
    }

    int averageOfSubtree(TreeNode* root) {
        int ctr = 0;

        dfs(root, ctr);

        return ctr;
    }
};