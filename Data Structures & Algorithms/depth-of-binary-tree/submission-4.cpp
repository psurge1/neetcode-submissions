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

        queue<TreeNode*> nodesToVisit;
        nodesToVisit.push(root);
        int levels = 0;
        while (!nodesToVisit.empty()) {
            ++levels;
            for (int ctr = 0, numNodes = nodesToVisit.size(); ctr < numNodes; ++ctr) {
                TreeNode* frontNode = nodesToVisit.front();
                nodesToVisit.pop();
                if (frontNode->left) {
                    nodesToVisit.push(frontNode->left);
                }
                if (frontNode->right) {
                    nodesToVisit.push(frontNode->right);
                }
            }
        }
        return levels;
    }
};
