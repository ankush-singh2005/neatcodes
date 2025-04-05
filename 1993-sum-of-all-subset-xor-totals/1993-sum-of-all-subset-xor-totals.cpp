class Solution {
public:
    void findSubsets(vector<int>& nums,vector<vector<int>> &subsets, vector<int> &ds, int n, int ind){
        if(ind==n){
            subsets.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        findSubsets(nums, subsets, ds, n, ind+1);
        ds.pop_back();
        findSubsets(nums, subsets, ds, n, ind+1);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> ds;
        int n=nums.size();
        findSubsets(nums, subsets, ds, n, 0);
        int sum=0;
        for(int i=0;i<subsets.size();i++){
            int x=0;
            for(int j=0;j<subsets[i].size();j++){
                x=x^subsets[i][j];
            }
            sum+=x;
        }
        return sum;
    }
};