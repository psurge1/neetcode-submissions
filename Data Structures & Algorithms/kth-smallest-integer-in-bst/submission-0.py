# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
        In order traversal of the tree

        Approach One: O(N) time, O(N) space
            Add all nodes of the tree to a stack
            Find the kth node
        Approach Two: O(N) time, O(1) space
            Find the smallest node
            Decrement from a k counter
            Record the node we arrive at when k counter is 0
        """

        if not root:
            return -1
        
        kCounter = k
        kthSmallestNum = -1
        
        def findKthSmallest(root):
            nonlocal kCounter
            nonlocal kthSmallestNum
            if not root or kCounter <= 0:
                return
            
            findKthSmallest(root.left)
            if kCounter == 1:
                kthSmallestNum = root.val
            kCounter -= 1
            findKthSmallest(root.right)
        
        findKthSmallest(root)
        return kthSmallestNum