class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums.size()%3!=0) return {};
        for(int i=0;i<nums.size();i=i+3){
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];

            if(abs(a-b)<=k && abs(b-c)<=k && abs(a-c)<=k){
                ans.push_back({a,b,c});
            }
            else{
                return {};
            }

        }
        return ans;
    }
};