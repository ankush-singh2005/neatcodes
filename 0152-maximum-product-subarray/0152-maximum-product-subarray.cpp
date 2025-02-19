class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=INT_MIN;
        int max2=INT_MIN;
        int prod=1;

        //left
        for(int i=0;i<nums.size();i++){
            if(prod==0) prod=1;
            prod=prod*nums[i];
            if(prod>max1) max1=prod;
        }

        //right
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(prod==0) prod=1;
            prod=prod*nums[i];
            if(prod>max2) max2=prod;
        }

        return max(max1,max2);
    }
};