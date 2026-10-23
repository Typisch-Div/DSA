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
    void reorderList(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *sec=slow->next;
        slow->next=nullptr;
        ListNode*prev=nullptr;
        while(sec){
            ListNode *nxt=sec->next;
            sec->next=prev;
            prev=sec;
            sec=nxt;
        }
        sec=prev;
        fast=head;
        while(sec){
            ListNode*t1=fast->next;
            ListNode*t2=sec->next;

            fast->next=sec;
            sec->next=t1;

            fast=t1;
            sec=t2;
        }
    }
};