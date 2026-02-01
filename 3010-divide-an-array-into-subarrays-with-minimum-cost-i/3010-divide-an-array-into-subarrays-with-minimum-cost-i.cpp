class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minSize=INT_MAX;
        for(int i=1;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                minSize=min(minSize,nums[0]+nums[i]+nums[j]);
            }
        }
        return minSize;
    }
};