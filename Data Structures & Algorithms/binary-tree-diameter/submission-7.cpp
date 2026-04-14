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
int dfs(TreeNode* node, int& maxDiam) {
    if (!node) {
        return 0;
    }
    int left = dfs(node->left, maxDiam);
    int right = dfs(node->right, maxDiam);

    maxDiam = max(maxDiam, 1 + left + right);
    int maxBranch = 1 + max(left, right);

    return maxBranch;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiam = 0;
        dfs(root, maxDiam);
        return maxDiam - 1;
    }
};
