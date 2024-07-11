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
    ListNode* sortList(ListNode* head) {
        ListNode *temp=head;
        vector<int> list;
        while(temp!=NULL){
            list.push_back(temp->val);
            temp=temp->next;
        }
        sort(list.begin(),list.end());
        ListNode *ans=new ListNode(-1);
        ListNode *dummy=ans;
        for(int i=0;i<list.size();i++){
            ListNode *curr=new ListNode(list[i]);
            dummy->next=curr;
            dummy=dummy->next;
        }
        return ans->next;
    }
};
