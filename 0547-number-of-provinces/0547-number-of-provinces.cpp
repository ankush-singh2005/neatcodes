class Solution {
public:
    void dfs( vector<bool> &visited, unordered_map<int, vector<int>> &adj, int u){
        if(!visited[u]) visited[u]=true;
        for(auto &v:adj[u]){
            if(!visited[v])
            dfs(visited, adj, v);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n, false);

        //making the adjacency list
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(visited, adj, i);
                count++;
            }
        }
        
        return count;
    }
};
