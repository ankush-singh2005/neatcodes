class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int miss;
        if(nums[nums.size()-1]==nums.size()-1){
            return nums.size();
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                miss=i;
                break;
            }
        }
        // if(i==nums[i])
        // miss=i+1;
        return miss;
    }
};
