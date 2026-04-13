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

        vector<pair<int, int>> heap;
        for (int i = 0; i < sz; ++i) {
            if (lists[i]) {
                heap.push_back(make_pair(lists[i]->val, i));
            }
        }
        make_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
        
        while (heap.size() > 0) {
            const pair<int, int> kv = heap[0];
            pop_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
            heap.pop_back();

            int node_val = kv.first;
            int list_index = kv.second;
            temp->next = lists[list_index];
            temp = temp->next;
            lists[list_index] = lists[list_index]->next;

            if (lists[list_index]) {
                heap.push_back(make_pair(lists[list_index]->val, list_index));
                push_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
            }
        }
        temp->next = nullptr;

        return dummy.next;
    }
};
