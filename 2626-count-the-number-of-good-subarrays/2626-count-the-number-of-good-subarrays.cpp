class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        long long ans=0;
        long long pairs=0;
        unordered_map<int,int> mp;
        while(j<nums.size()){
            if(mp[nums[j]]>0){
                pairs+=mp[nums[j]];
            }
            mp[nums[j]]++;
            while(pairs>=k){
                ans+=nums.size()-j;
                mp[nums[i]]--;
                pairs-=mp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};