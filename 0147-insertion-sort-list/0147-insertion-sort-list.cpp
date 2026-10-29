class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        while (head) {
            ListNode* nextNode = head->next;
            ListNode* curr = &dummy;

            while (curr->next && curr->next->val <= head->val)
                curr = curr->next;

            head->next = curr->next;
            curr->next = head;
            head = nextNode;
        }

        return dummy.next;
    }
};