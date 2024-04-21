class Solution {
    public:
        int numIdenticalPairs(vector<int>& nums) {
            int c=0;
            for(int j=nums.size()-1;j>=0;j--){
                for(int i=j-1;i>=0;i--){
                    if(nums[i]==nums[j]){
                        c++;
                    }
                }
            }
            return c;
    }
};
