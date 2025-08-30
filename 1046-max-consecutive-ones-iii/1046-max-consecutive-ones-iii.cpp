class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        unordered_map<int,int> mp;
        int maxLen=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(j-i+1 - mp[1]>k){
                mp[nums[i]]--;
                i++;
            }
            if(j-i+1 - mp[1]<=k) maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};