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
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }

        ListNode* tortoise = head;
        ListNode* hare = head->next;
        while (tortoise && hare && hare->next) {
            if (tortoise == hare) {
                return true;
            }
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        
        return false;
    }
};
