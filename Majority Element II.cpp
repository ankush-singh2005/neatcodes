class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        int ele=0;
        for(auto x:mp){
            if(x.second>n/3){
                ele=x.first;
                ans.push_back(ele);

            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        return ans;
    }
};
