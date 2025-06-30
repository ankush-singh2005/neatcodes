class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]+1)!=mp.end()){
                int length=mp[nums[i]]+mp[nums[i]+1];
                if(length>ans) ans=length;
            }
        }
        return ans;
    }
};