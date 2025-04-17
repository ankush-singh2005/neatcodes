class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long> mp;
        long long good=0;
        for(int i=0;i<nums.size();i++){
            int key=nums[i]-i;
            good+=mp[key];
            mp[key]++;
        }
        long long n=nums.size();
        long long total=n*(n-1)/2;
        return total-good;
    }
};