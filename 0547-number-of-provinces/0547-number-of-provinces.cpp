class Solution {
public:
    int n;
    void dfs( vector<bool> &visited, vector<vector<int>> &isConnected, int u){
        if(!visited[u]) visited[u]=true;
        for(int v=0;v<n;v++){
            if(!visited[v] && isConnected[u][v]==1)
            dfs(visited, isConnected, v);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool> visited(n, false);

        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(visited, isConnected, i);
                count++;
            }
        }
        
        return count;
    }
};
