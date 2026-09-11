# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        view = []
        queue = deque()
        if root is not None:
            queue.append(root)
        while len(queue) > 0:
            level_length = len(queue)
            view.append(queue[0].val)
            for _ in range(level_length):
                node = queue.popleft()
                if node.right is not None:
                    queue.append(node.right)
                if node.left is not None:
                    queue.append(node.left)
        
        return view