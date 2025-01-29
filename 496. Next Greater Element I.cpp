class Solution {
public:
    int findEle(int n, vector<int>& nums2){
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            st.push(nums2[i]);
        }
        int temp=-1;
        while(!st.empty()){
            if(st.top()>n) temp=st.top();
            if(st.top()==n) return temp;
            st.pop();
        }
        return temp;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int n=findEle(nums1[i],nums2);
            ans.push_back(n);
        }
        return ans;
    }
};
