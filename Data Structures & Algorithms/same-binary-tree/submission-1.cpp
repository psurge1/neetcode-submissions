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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;
        pq.push(p);
        qq.push(q);

        while (!pq.empty() && !qq.empty()) {
            TreeNode* np = pq.front();
            pq.pop();
            TreeNode* nq = qq.front();
            qq.pop();

            if (!np && !nq) {
                continue;
            }
            if (!np || !nq) {
                return false;
            }
            if (np->val != nq->val) {
                return false;
            }
            pq.push(np->left);
            pq.push(np->right);
            qq.push(nq->left);
            qq.push(nq->right);
        }

        return pq.size() == qq.size();
    }
};
