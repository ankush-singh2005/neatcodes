class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long count = 0;
        long result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count++;
            else if(count>0){
                result+=(count*(count+1))/2;
                count=0;
            } 
        }

        if(count>0) result+=(count*(count+1))/2;
        return result;
        }
    
};
