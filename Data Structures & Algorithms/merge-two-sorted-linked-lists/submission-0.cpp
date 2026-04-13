/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* builder = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                builder->next = list1;
                list1 = list1->next;
            }
            else {
                builder->next = list2;
                list2 = list2->next;
            }
            builder = builder->next;
        }
        if (list1) {
            builder->next = list1;
        }
        if (list2) {
            builder->next = list2;
        }

        return dummy.next;
    }
};
