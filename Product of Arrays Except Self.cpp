class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        //making two arrays named postfix and prefix and initialising it with 1.. like athe values at all indexes upto n have values n
        vector<int> prefix(n,1);
        vector<int> postfix(n,1);
        vector<int> ans(n);

        //making the postfix array.. by multipying the previous number in pre with the number in nums
        //in case of nums=[1,2,3,4] prefix is[1,1,2,6]
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }

      //similarly doing it with the postfix as well
      //for nums=[1,2,3,4] postfix is [24,12,4,1]
        for(int i=n-2;i>=0;i--){
            postfix[i]=postfix[i+1]*nums[i+1];
        }

      //placing the product of pre and post in the ans;
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*postfix[i];
        }
        return ans;
        
    }
};
