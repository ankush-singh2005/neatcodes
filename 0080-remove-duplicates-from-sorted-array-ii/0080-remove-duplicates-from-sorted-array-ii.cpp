class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=2;
        if(nums.size()<2) return nums.size();
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[ind-2]){
                nums[ind]=nums[i];
                ind++;
            }
        }
        return ind;
    }
};