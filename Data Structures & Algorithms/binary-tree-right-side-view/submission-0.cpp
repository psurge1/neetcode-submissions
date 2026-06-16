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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> rightMostNodes;

        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            for (int nodeIdx = 0, n = nodes.size(); nodeIdx < n; ++nodeIdx) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (nodeIdx == 0) {
                    rightMostNodes.push_back(node->val);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
                if (node->left) {
                    nodes.push(node->left);
                }
            }
        }
        return rightMostNodes;
    }
};
