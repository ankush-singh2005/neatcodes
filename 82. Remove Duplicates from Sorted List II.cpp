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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp=head;
        map<int,int> mp;
        while(temp!=nullptr){
            mp[temp->val]++;
            temp=temp->next;
        }
        ListNode *ans=new ListNode(-1);
        ListNode *dummy=ans;
        for(auto &x:mp){
            cout<<x.first<<" "<<x.second<<endl;
        }


        for(auto &x:mp){
            if(x.second==1){
                ListNode *node=new ListNode(x.first);
                dummy->next=node;
                dummy=dummy->next;
            }
        }
        return ans->next;
    }
};
