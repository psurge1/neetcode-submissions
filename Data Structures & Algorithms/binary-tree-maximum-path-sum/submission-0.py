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

        """
        on every recursive call, we want to return the max path value and max branch value
        then, we can determine if we want to form the max path value including the current "root"
        recursive function returns the max branch value, and updates the local max_path_value if it finds a larger path
        """

        def rec(node):
            nonlocal max_path_val
            branch_left = None
            branch_right = None
            path_val = node.val
            max_branch = None
            if node.left is not None:
                branch_left = rec(node.left)
                path_val += branch_left
                max_branch = branch_left
            if node.right is not None:
                branch_right = rec(node.right)
                path_val += branch_right
                if max_branch is None or max_branch < branch_right:
                    max_branch = branch_right

            max_path_val = max(max_path_val, path_val)
            if max_branch is None:
                max_branch = 0
            max_branch += node.val
            return max(0, max_branch)

        rec(root)
        
        return max_path_val