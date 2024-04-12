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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        //creating a new dummy LL which has only 0 as a node in it
        ListNode* dummy=new ListNode(0);

        //assigning temp to dummy;
        ListNode* temp=dummy;
        int carry=0;

        //checking here if l1 and l2 are null or not and also checking if carry exists
        while(l1!=NULL || l2!=NULL || carry){

            //here checking using terneray operator whether l1 and l2 exists or not if they do then add the value present or else add 0 and sum it all with the carry
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;

            //carry is equal to the sum/10
            carry=sum/10;

            //making a new node for temp and sending the value there.. sum%10 because we dont want the value to exceed from 10
            temp->next=new ListNode(sum%10);

            //changing temp to temp->next
            temp=temp->next;

            //checking if l1 exists and if it does then moving on to the next node
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
            
        }
        return dummy->next;


    }
};
