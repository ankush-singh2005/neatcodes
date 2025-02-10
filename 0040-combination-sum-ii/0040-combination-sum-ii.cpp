class Solution {
public:
    void combination(int ind, vector<int>& candidates, vector<vector<int>> &uniqueEle, vector<int>& ds, int target){
        if(target==0){
            uniqueEle.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i!=ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            combination(i+1,candidates,uniqueEle,ds,target-candidates[i]);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> uniqueEle;
        vector<int> ds;
        combination(0,candidates,uniqueEle,ds,target);
        return uniqueEle;
        

    }
};