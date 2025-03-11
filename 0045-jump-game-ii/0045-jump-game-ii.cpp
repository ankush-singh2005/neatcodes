class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        int maxReach=0, lastIndex=0;
        for(int i=0;i<nums.size()-1;i++){
            maxReach=max(maxReach, i+nums[i]);
            if(lastIndex==i){
                lastIndex=maxReach;
                ans++;
            }
        }
        return ans;
    }
};