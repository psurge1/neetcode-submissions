# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        def divide(lists, l, r) -> Optional[ListNode]:
            if r - l <= 0:
                return None
            if r - l == 1:
                return lists[l]
            if r - l == 2:
                return merge(lists[l], lists[l + 1])
            else:
                m = (r + l) // 2
                one = divide(lists, l, m)
                two = divide(lists, m, r)
                return merge(one, two)
        
        def merge(one: Optional[ListNode], two: Optional[ListNode]) -> Optional[ListNode]:
            dummy = ListNode()
            cpy = dummy
            while one and two:
                if one.val < two.val:
                    cpy.next = one
                    one = one.next
                else:
                    cpy.next = two
                    two = two.next
                cpy = cpy.next
            if one:
                cpy.next = one
            if two:
                cpy.next = two

            return dummy.next
        
        return divide(lists, 0, len(lists))