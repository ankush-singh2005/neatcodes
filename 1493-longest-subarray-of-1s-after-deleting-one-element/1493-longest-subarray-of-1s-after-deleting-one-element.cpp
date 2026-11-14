class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int zeroCount=0,ans=0;

        while(j<nums.size()){
            if(nums[j]==0) zeroCount++;

            while(zeroCount>1){
                if(nums[i]==0) zeroCount--;
                i++;
            }
            ans=max(j-i+1,ans);

            j++;
        }
        return ans-1;
    }
};