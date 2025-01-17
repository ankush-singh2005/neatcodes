class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=-1){
                int j=i;
                int count=0;
                while(nums[j]!=-1){
                    int k=nums[j];
                    nums[j]=-1;
                    j=k;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
