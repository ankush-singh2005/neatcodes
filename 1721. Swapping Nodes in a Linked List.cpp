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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> temp;
        ListNode* dummy=head;

        while(dummy!=nullptr){
            temp.push_back(dummy->val);
            dummy=dummy->next;
        }
        if(temp.size()==1){
            return head;
        }

        int a=temp[k-1];
        temp[k-1]=temp[temp.size()-k];
        temp[temp.size()-k]=a;

        cout<<temp[k-1]<<" "<<temp[temp.size()-k];

        int count=0;
        // ListNode* ansTemp=new ListNode(0);
        ListNode* ans=nullptr;
        ListNode* f =nullptr;
        while(count<temp.size()){
            ListNode* newNode =new ListNode(temp[count]);    
            if(ans==nullptr){
                ans = newNode;
                f= ans;
            }
            ans->next=newNode;
            ans=newNode;
            count++;
        }
        return f;
    }
};
