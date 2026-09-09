# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        cpy = head
        size = 0
        while cpy:
            size += 1
            cpy = cpy.next
        
        dummy = ListNode()
        dummy.next = head
        cpy = dummy
        for _ in range(size - n):
            cpy = cpy.next
        cpy.next = cpy.next.next
        return dummy.next