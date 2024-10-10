class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int i=0,j=0;
        int m=INT_MIN;
        while(j<nums.size()){
            if(nums[j]==1) ans++;
            if(nums[j]!=1||j==nums.size()-1){
                m=max(m,ans);
                i=j+1;
                ans=0;

            }
            j++;
        }
        return m;
    }
};
