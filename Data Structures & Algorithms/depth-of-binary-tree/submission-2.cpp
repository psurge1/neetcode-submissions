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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int maxDepth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++maxDepth;
            for (int node = 0, n = q.size(); node < n; ++node) {
                TreeNode* tnode = q.front();
                q.pop();
                if (tnode->left) {
                    q.push(tnode->left);
                }
                if (tnode->right) {
                    q.push(tnode->right);
                }
            }
        }

        return maxDepth;
    }
};
