class Solution {
public:
    int m;
    int n;

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i>=m||i<0||j>=n||j<0||grid[i][j]!='1') return;
        grid[i][j]='$';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};