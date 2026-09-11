# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        max_path_val = root.val

        def rec(node):
            nonlocal max_path_val
            if node is None:
                return 0
            
            branch_left = rec(node.left)
            branch_right = rec(node.right)
            path_val = node.val + branch_left + branch_right
            max_branch = max(branch_left, branch_right) + node.val

            max_path_val = max(max_path_val, path_val)

            return max(0, max_branch)

        rec(root)
        
        return max_path_val