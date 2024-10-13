class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> v(nums.size(),-1);
        for(int i=0;i<nums.size()*2;i++){
            int n=i%nums.size();
            while(!st.empty()&&nums[n]>nums[st.top()]){
                v[st.top()]=nums[n];
                st.pop();
            }
            if(i<nums.size()){
                st.push(i);
            }
        }
        return v;
    }
};
