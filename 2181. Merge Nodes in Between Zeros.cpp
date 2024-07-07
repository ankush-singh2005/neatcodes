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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ans=new ListNode(-1);
        ListNode *dummy=ans;
        ListNode *temp=head->next;
        int sum=0;
        while(temp->next!=nullptr){
            sum=sum+temp->val;
            if(temp->val==0){
                ListNode *s=new ListNode(sum);
                dummy->next=s;
                dummy=dummy->next;
                sum=0;
            }
            temp=temp->next;
            
        }
        dummy->next=new ListNode(sum);
        return ans->next;
    }
};
