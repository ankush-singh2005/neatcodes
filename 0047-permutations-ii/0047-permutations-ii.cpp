class Solution {
public:
    void solve(vector<int>& nums, vector<bool> &visited, vector<vector<int>> &ans, vector<int> &temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]==true) continue;
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]!= true) continue;
            visited[i]=true;
            temp.push_back(nums[i]);
            solve(nums,visited,ans,temp);
            temp.pop_back();
            visited[i]=false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());


        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,visited,ans,temp);
        return ans;
    }
};