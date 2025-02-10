class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=1;
        if(nums.size()==0) return 0;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto i:st){
            if(st.find(i-1)==st.end()){
                int cnt=1;
                int ele=i;
                while(st.find(ele+1)!=st.end()){
                    cnt++;
                    ele=ele+1;
                }
                longest=max(longest,cnt);
            }
            else continue;
        }
        return longest;
    }
};