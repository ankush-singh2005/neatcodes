class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        
        if(nums.size()<=1) return true;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) count++;
        }
        if(nums[0]<nums[nums.size()-1]) count++;
        return count<=1;
    }
};