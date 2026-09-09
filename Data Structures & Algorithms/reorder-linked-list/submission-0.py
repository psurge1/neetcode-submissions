# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        First Attempt:
            split the linked list in half
            reverse the second half of the linked list
            insert the reversed half
        """

        one = head
        size = 0
        while one:
            size += 1
            one = one.next
        
        ## isolate half of the linked list
        one = head
        two = head
        skipCount = math.ceil(size / 2)
        while skipCount > 0:
            two = two.next
            skipCount -= 1
        
        ## reverse second half of the linked list
        prev = None
        curr = two
        while curr is not None:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        two = prev

        ## merge reversed second half into first half
        ## either size(one) == size(two) or size(one) = size(two) + 1
        while one is not None and two is not None:
            one_next = one.next
            one.next = two
            two_next = two.next
            two.next = one_next
            one = one_next
            two = two_next
        one.next = None