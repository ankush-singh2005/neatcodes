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
        ListNode* oddNode=new ListNode();
        ListNode* odd=oddNode;

        ListNode* var=head;
        // ListNode* even=new ListNode();
        int count=1;
        while(var!=nullptr){
            if(count%2!=0){
                ListNode* newnode=new ListNode(var->val);
                oddNode->next=newnode;
                oddNode=oddNode->next;

            }
            count++;
            var=var->next;
        }
        // return odd->next;
        ListNode* evenNode=new ListNode();
        ListNode* even=evenNode;

        var=head;
        count=1;
        while(var!=nullptr){
            if(count%2==0){
                ListNode* newnode=new ListNode(var->val);
                evenNode->next=newnode;
                evenNode=evenNode->next;

            }
            count++;
            var=var->next;
        }

        ListNode* ans=even->next;
        oddNode->next=ans;
        return odd->next;



    }
};
