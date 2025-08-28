class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int i=0,j=0;
       int count=0;
       int ans=0;
       while(j<nums.size()){
        if(nums[j]%2!=0){
            count++;
        }

        while(count>k){
            if(nums[i]%2!=0) count--;
            i++;
        }
        if(count==k){
            int temp=i;
            while(nums[temp]%2==0){
                temp++;
            }
            int prefixEvens=temp-i;
            ans+=prefixEvens+1;
        }
        j++;
       }
       return ans; 
    }
};