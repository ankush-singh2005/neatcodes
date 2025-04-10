class Solution {
public:
    void recurPermute(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, vector<int> &freq){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]&& !freq[i-1]) continue;
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermute(nums,ans,ds,freq);
                ds.pop_back();
                freq[i]=0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        vector<int> freq(nums.size(),0);
        recurPermute(nums,ans,ds,freq);
        return ans;
    }
};