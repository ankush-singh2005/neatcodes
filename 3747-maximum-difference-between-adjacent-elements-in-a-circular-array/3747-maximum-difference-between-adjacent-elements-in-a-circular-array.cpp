class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        nums.insert(nums.end(),nums.begin(),nums.end());
        int max=0;
        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1])>max) max=abs(nums[i]-nums[i+1]);
        }
        return max;
    }
};