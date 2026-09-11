# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        small, large = p.val, q.val
        if small > large:
            small, large = large, small
        
        if small <= root.val and root.val <= large:
            return root
        if root.val < small:
            return self.lowestCommonAncestor(root.right, p, q)
        return self.lowestCommonAncestor(root.left, p, q)