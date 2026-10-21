class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto node : lists)
            if (node) pq.push(node);
        ListNode dummy(0), *tail = &dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
            if (node->next) pq.push(node->next);
        }
        tail->next = nullptr;
        return dummy.next;
    }
};