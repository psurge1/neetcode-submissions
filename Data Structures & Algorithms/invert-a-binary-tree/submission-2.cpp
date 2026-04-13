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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        deque<TreeNode*> nodes;
        nodes.push_back(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop_front();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left) {
                nodes.push_back(node->left);
            }
            if (node->right) {
                nodes.push_back(node->right);
            }
        }
        return root;
    }
};
