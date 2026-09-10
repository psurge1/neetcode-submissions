# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        """
        iterate until we reach the k + 1th node
        reverse the first k nodes
        rejoin both lists
        iterate past the k + kth node
        repeat
        """

        dummy = ListNode()
        dummy.next = head
        prev_tail = dummy
        next_group = head

        
        while True:
            v = k
            while v > 0 and next_group:
            # next_group will be the next node after our reversed list
                next_group = next_group.next
                v -= 1
            # break early to avoid reversing groups with size < k
            if next_group is None and v > 0:
                break
            
            # reverse nodes between prev_tal and next_group
            curr = prev_tail.next
            next_prev_tail = curr
            prev = next_group
            while curr != next_group:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
            prev_tail.next = prev

            # iterate to next start position and repeat
            prev_tail = next_prev_tail

            if next_group is None:
                break

        return dummy.next