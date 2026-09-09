"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None

        # map old nodes to their new copies
        copiedVersions: dict[Node, Node] = dict()
        cpy = head
        while cpy:
            if cpy not in copiedVersions:
                copiedVersions[cpy] = Node(cpy.val)
            cpy = cpy.next
        
        cpy = head
        while cpy:
            if cpy.next:
                copiedVersions[cpy].next = copiedVersions[cpy.next]
            if cpy.random:
                copiedVersions[cpy].random = copiedVersions[cpy.random]
            cpy = cpy.next
        return copiedVersions[head]