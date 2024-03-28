class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int total=0;
        int res=INT_MAX;
        for(int r=0;r<nums.size();r++){
            total=total+nums[r];
            while(total>=target){
                res=min((r-l+1),res);
                total=total-nums[l];
                l++;
            }
        }
        if(res==INT_MAX) return 0;
        else return res;
    }
};
