class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int size=n*n;
        vector<int> count(size+1,0);
        vector<int> ans(2,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                count[grid[i][j]]++;
            }
        }
        for(int i=0;i<count.size();i++){
            if(count[i]==2) ans[0]=i;
            if(count[i]==0) ans[1]=i;
        }
        return ans;
    }
};