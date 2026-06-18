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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;

        if (!root) {
            return levels;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            vector<int> level;
            for (int nodeIdx = 0, levelSize = nodes.size(); nodeIdx < levelSize; ++nodeIdx) {
                TreeNode* node = nodes.front();
                nodes.pop();

                level.push_back(node->val);
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
            levels.push_back(std::move(level));
        }
        return levels;
    }
};
