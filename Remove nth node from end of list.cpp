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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* temp=head;
      int counter = 0;

      //finding the size of the LL
      while(temp!=nullptr){
        counter++;
        temp=temp->next;
      }

      //if we have to delete the first node ie n==counter
      if(n==counter){
        ListNode* del=head;
        head=head->next;
        delete del;
        return head;
      }

      //taking current to the node before the node to be deleted
      ListNode* cur=head;
      int c2=0;

      //doing this to find the node to be deletd from the start of the end
      while(c2!=counter-n-1){
        c2++;
        cur=cur->next;
      }

      //placing the value of the node to be deletd in a variable
      ListNode* del=cur->next;

      //skipping the node to be deleted
      cur->next=cur->next->next;

      //deleting the node
      delete del;
      return head;
    }
};
