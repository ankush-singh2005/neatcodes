class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> st;
        int i=0,j=0;
        while(j<n){
            
            //agar range se bahar nikl gye to nums[i] ko remove karenge from the set
            if(abs(i-j)>k){
                st.erase(nums[i]);
                i++;
            }
            //find karenge ki nums[j] set me present h ki ni
            if(st.find(nums[j])!=st.end()) return true;

            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};
