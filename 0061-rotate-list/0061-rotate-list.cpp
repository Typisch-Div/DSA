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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        ListNode* temp = head;
        int cnt = 1;
        while (temp->next) {
            cnt++;
            temp = temp->next;
        }
        k = k % cnt;

        if (k == 0)
            return head;

        temp->next = head;

        int steps = cnt - k;
        temp = head;

        for (int i = 1; i < steps; i++) {
            temp = temp->next;
        }
        ListNode* start = temp->next;
        temp->next = nullptr;
        return start;
    }
};