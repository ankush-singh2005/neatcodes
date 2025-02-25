class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        
        if (l1) temp->next = l1;
        else temp->next = l2;
        
        return dummy.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeTwoLists(l1, l2));
            }
            
            lists = mergedLists;
        }
        
        return lists[0];
    }
};
