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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *temp=head->next;
        ListNode *compare=head;
        vector<int> result;
        int counter=2;
        while(temp->next!=nullptr){
            //for local maxima
            if(temp->val>compare->val && temp->val>temp->next->val  ){
                result.push_back(counter);
            }

            //for local minima
            if(temp->val<compare->val && temp->val<temp->next->val  ){
                result.push_back(counter);
            
            }


            temp=temp->next;
            compare=compare->next;
            counter++;
        }

        vector<int> ans(2,-1);
        int min=INT_MAX;
        if(result.size()<2) return ans;
        for(int i=0;i<result.size()-1;i++){
            if(abs(result[i]-result[i+1])<min) min=abs(result[i]-result[i+1]);
        }
        ans[0]=min;
        ans[1]=abs(result[0]-result[result.size()-1]);
        // ans.push_back(result[0]-result[result.size()-1]);
        

        return ans;

    }
};
