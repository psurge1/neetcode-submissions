# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:  
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        """
        Real problem: given two trees, 
            are the trees the same, or 
            is the second tree the same as the left or right subtree
        """

        if not root and not subRoot:
            return True
        if not root or not subRoot:
            return False
        
        def isSameTree(rootOne, rootTwo):
            if not rootOne and not rootTwo:
                return True
            if not rootOne or not rootTwo:
                return False
            return rootOne.val == rootTwo.val and isSameTree(rootOne.left, rootTwo.left) and isSameTree(rootOne.right, rootTwo.right)

        if isSameTree(root, subRoot):
            return True
        return self.isSubtree(root.right, subRoot) or self.isSubtree(root.left, subRoot)