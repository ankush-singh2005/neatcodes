class Solution {
public:
    void solve(vector<int>& nums, int target, vector<vector<int>> &ans, vector<int> &temp, int &sum, int index){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            sum=sum+nums[i];
            temp.push_back(nums[i]);
            solve(nums,target,ans,temp,sum,i);
            sum=sum-nums[i];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int sum=0;
        solve(nums,target,ans,temp,sum,0);
        return ans;
    }
};