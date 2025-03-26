class Solution {
public:
    void bfs( vector<bool> &visited, unordered_map<int, vector<int>> &adj, int u){
        queue<int> q;
        q.push(u);
        visited[u]=true;
        while(!q.empty()){
            int source=q.front();
            q.pop();
            for(auto &v:adj[source]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
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
                bfs(visited, adj, i);
                count++;
            }
        }
        
        return count;
    }
};
