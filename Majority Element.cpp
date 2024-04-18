class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int max=0;
        int ele=0;
        for(auto x:mp){
            if(x.second>max){
                ele=x.first;
                max=x.second;
            }
        }
        return ele;
        
    }
};
