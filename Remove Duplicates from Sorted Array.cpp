class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num=nums[0];
        int count=1;
        vector<int> ans;
        ans.push_back(num);
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=num){
                num=nums[i];
                count++;
                ans.push_back(num);
            }
        }
        nums=ans;
        return count;
    }
};
