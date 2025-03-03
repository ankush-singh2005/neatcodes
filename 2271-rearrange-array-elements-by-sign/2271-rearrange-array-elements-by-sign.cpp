class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int pos=0,neg=1;
        int cnt=0;
        while(cnt<nums.size()){
            if(nums[cnt]>0){
                ans[pos]=nums[cnt];
                pos+=2;
                cnt++;
            }
            else{
                ans[neg]=nums[cnt++];
                neg+=2;
            }
        }
        return ans;
    }
};