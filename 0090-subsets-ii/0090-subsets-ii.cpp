class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp, int index){
        ans.push_back(temp);

        for(int j=index;j<nums.size();j++){
            if(j>index && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            solve(nums,ans,temp,j+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,ans,temp,0);
        return ans;
    }
};