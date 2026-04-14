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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int maxDiam = 0;
        unordered_map<TreeNode*, int> branchDepth;
        branchDepth[nullptr] = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            if (branchDepth.find(node->left) == branchDepth.end()) {
                stk.push(node->left);
                continue;
            }
            if (branchDepth.find(node->right) == branchDepth.end()) {
                stk.push(node->right);
                continue;
            }
            maxDiam = max(maxDiam, 1 + branchDepth[node->left] + branchDepth[node->right]);
            branchDepth[node] = 1 + max(branchDepth[node->left], branchDepth[node->right]);
            stk.pop();
        }

        return maxDiam - 1;
    }
};
