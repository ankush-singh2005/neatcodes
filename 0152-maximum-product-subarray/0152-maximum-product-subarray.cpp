class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int m1=INT_MIN;
        int m2=INT_MIN;

        //finding out the max product subarray when going left to right
        for(int i=0;i<nums.size();i++){
            if(prod==0) prod=1;
            prod*=nums[i];
            if(prod>m1) m1=prod;
        }

        //finding out the max product subarray when going right to left
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(prod==0) prod=1;
            prod*=nums[i];
            if(prod>m2) m2=prod;
        }
        return max(m1,m2);
    }
};