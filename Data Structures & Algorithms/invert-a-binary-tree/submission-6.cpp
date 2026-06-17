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
        queue<TreeNode*> inversionQueue;
        inversionQueue.push(root);
        while (!inversionQueue.empty()) {
            TreeNode* top = inversionQueue.front();
            inversionQueue.pop();
            if (top) {
                TreeNode* temp = top->right;
                top->right = top->left;
                top->left = temp;
                inversionQueue.push(top->left);
                inversionQueue.push(top->right);
            }
        }
        return root;
    }
};
