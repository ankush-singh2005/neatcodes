class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,count=0;
        int ans=INT_MAX;
        while(j<nums.size()){
            count=count+nums[j];
            while(count>=target){
                ans=min(ans,j-i+1);
                count=count-nums[i];
                i++;
            }
            j++;
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};