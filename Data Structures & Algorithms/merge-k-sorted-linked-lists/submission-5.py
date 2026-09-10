# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        
        def merge(one, two):
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
        
        while len(lists) > 1:
            merged = []
            for i in range(0, len(lists), 2):
                one = lists[i]
                two = None
                if i + 1 < len(lists):
                    two = lists[i + 1]
                merged.append(merge(one, two))
            lists = merged
        
        return lists[0]