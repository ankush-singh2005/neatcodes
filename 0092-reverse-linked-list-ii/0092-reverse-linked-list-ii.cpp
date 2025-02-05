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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;

        //taking prev to the node from where we have to start the reversal
        for(int i=1;i<left;i++){
            prev=prev->next;
        }

        //making a curr node that is right next to the previos
        ListNode* curr=prev->next;

        for(int i=0;i<right-left;i++){
            ListNode* temp=prev->next;
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=temp;
        }
        return dummy->next;
    }
};