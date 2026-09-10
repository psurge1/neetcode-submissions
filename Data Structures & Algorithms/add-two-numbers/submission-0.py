# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        solution = ListNode()
        res = solution

        carry = 0
        while l1 is not None or l2 is not None:
            digit_sum = carry
            if l1 is not None:
                digit_sum += l1.val
            if l2 is not None:
                digit_sum += l2.val
            
            carry = 0
            if digit_sum >= 10:
                digit_sum -= 10
                carry = 1
            res.next = ListNode(digit_sum)

            res = res.next
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next
        if carry > 0:
            res.next = ListNode(1)


        return solution.next