# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class ComparableNode:
    def __init__(self, node: ListNode):
        self.node = node
    
    def __lt__(self, other: ComparableNode):
        return self.node.val < other.node.val

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap: list[ComparableNode] = []
        for l in lists:
            if l is not None:
                heapq.heappush(heap, ComparableNode(l))
        
        dummy = ListNode()
        cpy = dummy
        while len(heap) > 0:
            top = heapq.heappop(heap)
            if top.node.next:
                heapq.heappush(heap, ComparableNode(top.node.next))
            cpy.next = top.node
            cpy = cpy.next

        
        return dummy.next