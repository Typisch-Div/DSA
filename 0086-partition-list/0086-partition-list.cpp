class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0), large(0);
        ListNode* a = &small;
        ListNode* b = &large;

        while (head) {
            if (head->val < x) {
                a->next = head;
                a = a->next;
            } else {
                b->next = head;
                b = b->next;
            }

            head = head->next;
        }

        b->next = nullptr;
        a->next = large.next;

        return small.next;
    }
};