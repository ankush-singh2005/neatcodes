class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if(nums.size()<3) return 0;
        long long maxVal=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    long long triplet = (long long)(nums[i]-nums[j])*
                    nums[k];
                    maxVal=max(maxVal,triplet);
                }
            }
        }
        return maxVal;
    }
};