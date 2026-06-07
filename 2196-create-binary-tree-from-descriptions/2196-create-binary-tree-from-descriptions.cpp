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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> childs;

        for (auto description: descriptions){
            int parent = description[0];
            int child = description[1];
            bool isLeft = description[2];

            if (nodeMap.count(parent) == 0) {
                nodeMap[parent] = new TreeNode(parent);
            }
            if (nodeMap.count(child) == 0){
                nodeMap[child] = new TreeNode(child);
            }

            if (isLeft) {
                nodeMap[parent]->left = nodeMap[child];
            } else {
                nodeMap[parent]->right = nodeMap[child];
            }

            childs.insert(child);
        }

        for (auto p: nodeMap) {
            auto node = p.second;
            // debug(p.first);
            // debug(node->val);

            // 50 gk ada di set childs, jadi return dia sebagai root
            if (childs.find(p.first) == childs.end()){
                return node;
            }
        }

        return nullptr;
    }
};