# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


"""
Biggest mistakes I made:
- inconsistency in tree traversal: did dfs on serialize and bfs on deserialize, needed to do level order traversal (bfs) in both serialize and deserialize
- forgetting to call a nested function that I defined
- getting stuck on a portion of the problem

What I need to do when stuck
- Write out the problem
- broadly specify the steps I need to take to go from point a to point b
- write down ideas
- evaluate them, and adjust them
- implement an idea that im eventually happy with
"""
class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        res = []

        queue = deque()
        queue.append(root)
        while len(queue) > 0:
            node = queue.popleft()
            if node is None:
                res.append("#")
            else:
                res.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)

        return ",".join(res)
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        node_items = deque(data.split(","))

        if node_items[0] == "#":
            return None
        
        num_nodes = len(node_items)
        """
        getting stuck on how to convert a level-order queue to a tree
        level order means all nodes of the same level are adjacent

        Steps
        - create a node
        - add it to a populate_children queue
        - when you pop from populate_children, pop 2 from node_items to create 2 children

        we know that every non null (not #) node will have 2 children (possibly null) as well
        this means that for every node in populate_children, there must be 2 children in node_items
        """
        head = TreeNode(int(node_items[0]))
        node_items.popleft()

        populate_children = deque()
        populate_children.append(head)

        while len(populate_children) > 0:
            parent_node = populate_children.popleft()
            lc_val = node_items.popleft()
            rc_val = node_items.popleft()
            if lc_val != "#":
                parent_node.left = TreeNode(int(lc_val))
                populate_children.append(parent_node.left)
            if rc_val != "#":
                parent_node.right = TreeNode(int(rc_val))
                populate_children.append(parent_node.right)

        return head