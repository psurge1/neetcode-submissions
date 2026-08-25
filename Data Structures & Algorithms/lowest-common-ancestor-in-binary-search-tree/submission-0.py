# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        """
        Find the first node such that 
            the smaller node is under the root and the larger node is greater than the node
        Edge case:
            what if the root is p or q? 
                This test case isn't possible since a lowest common ancestor 
                cannot be the same node as p or q
            duplicate nodes?
                all node values are unique
        Approach one O(N^2):
            for each node, search for the smaller node on the left subtree and
            search for the larger node on the right subtree. if both nodes are found,
            we found our LCA
        Approach two:
            if the root is larger/smaller than both p and q, it cannot be the LCA. Adjust (l or r)

        """

        smaller = q.val
        larger = p.val
        if larger < smaller:
            smaller, larger = larger, smaller
        
        def findLCA(root, smaller, larger):
            if root.val > larger:
                return findLCA(root.left, smaller, larger)
            if root.val < smaller:
                return findLCA(root.right, smaller, larger)
            return root

        return findLCA(root, smaller, larger)