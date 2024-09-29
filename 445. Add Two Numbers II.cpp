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
    ListNode* reverse(ListNode* l1){
        ListNode* prev=NULL;
        ListNode* curr=l1;
        while(curr!=NULL){
            ListNode* forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1=reverse(l1);
        ListNode* list2=reverse(l2);

        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(list1!=nullptr || list2!=nullptr || carry!=0){
            int sum=0;

            if(list1!=nullptr){
                sum=sum+list1->val;
                list1=list1->next;
            }

            if(list2!=nullptr){
                sum=sum+list2->val;
                list2=list2->next;
            }

            sum=sum+carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return reverse(dummy->next
        );



        
    }
};
