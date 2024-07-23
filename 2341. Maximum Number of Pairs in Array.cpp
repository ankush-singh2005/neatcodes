class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int pair,left=0;
        for(auto &x:mp){
            if(x.second%2!=0) left++;
            pair=pair+(x.second/2);
        }
        cout<<pair<<" "<<left;
        return {pair,left};
        
    }
};
