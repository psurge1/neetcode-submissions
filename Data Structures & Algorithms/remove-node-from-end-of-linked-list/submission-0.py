# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        def rec(prev, node, n) -> int:
            if node is None:
                return n
            res = rec(node, node.next, n)
            if res == 1:
                prev.next = node.next
            return res - 1
        dummy = ListNode()
        dummy.next = head
        rec(dummy, head, n)
        return dummy.next