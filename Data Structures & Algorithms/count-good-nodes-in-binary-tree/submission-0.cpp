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
private:
    int countGoodNodes(TreeNode* node, int maxNodeVal) {
        if (!node) {
            return 0;
        }

        int count = 0;
        if (node->val >= maxNodeVal) {
            maxNodeVal = node->val;
            ++count;
        }
        count += countGoodNodes(node->left, maxNodeVal) + countGoodNodes(node->right, maxNodeVal);
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + countGoodNodes(root->left, root->val) + countGoodNodes(root->right, root->val);
    }
};
