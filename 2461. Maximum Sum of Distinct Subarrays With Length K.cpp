class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        long long sum=0;
        long long m=0;
        unordered_set<int> st;
        while(j<nums.size()){

            //If the element at nums[j] is already in the set, we shrink the window from the left
            while(st.find(nums[j])!=st.end()){
                sum-=nums[i]; // Remove the leftmost element from the sum
                st.erase(nums[i]); // Remove it from the set as well
                i++; // Move the left pointer to the right
            }

            st.insert(nums[j]);
            sum+=nums[j];
            if(j-i+1==k){
                if(st.size()==k){
                    m=max(m,sum);

                    sum=sum-nums[i];
                    st.erase(nums[i]);
                    i++;
                }
                else{
                    sum=sum-nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
            j++;
        }
        if(m==INT_MIN) return 0; else return m;

    }
};
