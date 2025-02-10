class Solution {
public:
    void subs(int ind, vector<int>& nums, int n, vector<vector<int>> &ans, vector<int> &ds){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        subs(ind+1,nums,n,ans,ds);
        ds.pop_back();
        subs(ind+1,nums,n,ans,ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n=nums.size();
        subs(0,nums,n,ans,ds);
        return ans;
    }
};