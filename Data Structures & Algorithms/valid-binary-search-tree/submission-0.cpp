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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            true;
        }
        
        int runningVal = -1001;
        unordered_set<TreeNode*> visited;
        stack<TreeNode*> nodesToProcess;
        nodesToProcess.push(root);
        while (!nodesToProcess.empty()) {
            TreeNode* node = nodesToProcess.top();
            cout << node->val << endl;
            if (node->left && !visited.contains(node->left)) {
                nodesToProcess.push(node->left);
                continue;
            }
            visited.insert(node);
            if (node->val <= runningVal) {
                return false;
            }
            runningVal = node->val;
            nodesToProcess.pop();
            if (node->right) {
                nodesToProcess.push(node->right);
            }
        }

        return true;
    }
};
