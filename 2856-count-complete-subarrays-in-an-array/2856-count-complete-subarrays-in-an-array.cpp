class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        int count=0;
        for(auto i:nums) st.insert(i);
        for(int i=0;i<nums.size();i++){
            set<int> s;
            for(int j=i;j<nums.size();j++){
                s.insert(nums[j]);
                if(s==st) count++;
            }
        }
        return count;
    }
};