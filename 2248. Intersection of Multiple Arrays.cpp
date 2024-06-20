class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mp[nums[i][j]]++;
            }
        }
        for(auto& x:mp){
            // cout<<x.first<<" "<<x.second<<endl;
            if(x.second==nums.size())
            ans.push_back(x.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
