# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = []

        nodes = deque()
        if root is not None:
            nodes.append(root)
        
        while len(nodes) > 0:
            size = len(nodes)
            level = []
            for _ in range(size):
                node = nodes.popleft()
                level.append(node.val)
                if node.left is not None:
                    nodes.append(node.left)
                if node.right is not None:
                    nodes.append(node.right)
            levels.append(level)
        
        return levels