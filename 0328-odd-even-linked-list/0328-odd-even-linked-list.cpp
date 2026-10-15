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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* ehead=head->next;
        ListNode* t1=head;
        ListNode* t2=ehead;
        while (t2 != nullptr && t2->next != nullptr){
            t1->next = t2->next;
            t1 = t1->next;

            t2->next = t1->next;
            t2 = t2->next;
        }
        t1->next = ehead;
        return head;
    }
};