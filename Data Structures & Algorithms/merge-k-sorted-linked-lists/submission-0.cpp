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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        ListNode dummy;
        ListNode* temp = &dummy;
        
        int smallest = 0;
        while (smallest >= 0) {
            smallest = -1;
            for (int i = 0; i < sz; ++i) {
                if (lists[i]) {
                    if (smallest == -1 || lists[i]->val < lists[smallest]->val) {
                        smallest = i;
                    }
                }
            }

            if (smallest != -1) {
                temp->next = lists[smallest];
                lists[smallest] = lists[smallest]->next;
                temp = temp->next;
            }
        }

        return dummy.next;
    }
};
