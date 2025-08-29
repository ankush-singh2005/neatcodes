class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int prefixSum=0;
        int cnt=0;
        unordered_map<int,int> mp;
        mp.insert({0,1});
        for(int i=0;i<nums.size();i++){
            prefixSum=prefixSum+nums[i];
            if(mp.find(prefixSum-k)!=mp.end()){
                cnt+=mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }
        return cnt;
    }
};