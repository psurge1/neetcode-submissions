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
pair<int, int> dfs(TreeNode* node) {
    if (!node) {
        return {0, 0};
    }
    pair<int, int> left = dfs(node->left);
    pair<int, int> right = dfs(node->right);

    int diamWithNode = 1 + left.second + right.second;
    int maxBranch = 1 + max(left.second, right.second);

    return {max(max(left.first, right.first), diamWithNode), maxBranch};
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first - 1;
    }
};
