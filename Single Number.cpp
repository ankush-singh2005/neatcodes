class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1 && nums[0]!=-1){
            return 1;
        }

        if(nums.size()==1 && nums[0]==-1){
            return -1;
        }

        sort(nums.begin(),nums.end());

        if(nums[nums.size()-2]!=nums[nums.size()-1])
        return nums[nums.size()-1];

        if(nums[0]!=nums[1])
        return nums[0];


        int single;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]&&nums[i]!=nums[i-1])
            single=nums[i];
        }
        return single;
    }
};
