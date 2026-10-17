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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)    return head;
        ListNode* pre=nullptr;
        ListNode* fro=nullptr;
        ListNode* temp=head;
        while(temp!=nullptr){
            fro= temp->next;
            temp->next=pre;
            pre=temp;
            temp=fro;
        }
        return pre;
    }
};