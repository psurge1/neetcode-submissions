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
        vector<tuple<int, ListNode*>> heap;
        for (ListNode* ln : lists) {
            if (ln) {
                heap.emplace_back(ln->val, ln);
            }
        }
        make_heap(heap.begin(), heap.end(), greater<tuple<int, ListNode*>>());

        ListNode dummy;
        ListNode* cpy = &dummy;
        while (heap.size() > 0) {
            pop_heap(heap.begin(), heap.end(), greater<tuple<int, ListNode*>>());
            auto [val, node] = heap.back();
            heap.pop_back();
            if (node->next) {
                heap.emplace_back(node->next->val, node->next);
                push_heap(heap.begin(), heap.end(), greater<tuple<int, ListNode*>>());
            }
            cpy->next = node;
            cpy = cpy->next;
        }
        return dummy.next;
    }
};
