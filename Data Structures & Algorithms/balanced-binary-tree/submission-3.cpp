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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        unordered_map<TreeNode*, int> depthFromNode;
        depthFromNode[nullptr] = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            if (depthFromNode.find(node->left) == depthFromNode.end()) {
                stk.push(node->left);
                continue;
            }
            if (depthFromNode.find(node->right) == depthFromNode.end()) {
                stk.push(node->right);
                continue;
            }
            stk.pop();
            depthFromNode[node] = 1 + max(depthFromNode[node->left], depthFromNode[node->right]);
            if (abs(depthFromNode[node->left] - depthFromNode[node->right]) > 1) {
                return false;
            }
        }
        return true;
    }
};
