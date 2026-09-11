# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0
        

        def count(node, maxVal):
            if node is None:
                return 0
            res = 0
            if maxVal <= node.val:
                res += 1
                maxVal = node.val
            res += count(node.left, maxVal) + count(node.right, maxVal)
            return res 

        
        return 1 + count(root.left, root.val) + count(root.right, root.val)