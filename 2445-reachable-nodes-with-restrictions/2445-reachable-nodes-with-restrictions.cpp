class Solution {
public:
    void count(int &ans, vector<vector<int>> &adj, vector<bool> &visited, int u, unordered_set<int> &restrictedSet){
        if (visited[u] || restrictedSet.count(u)) return; // Skip restricted nodes
        visited[u]=true;
        ans++;
        for(auto &v:adj[u]){
            if(!visited[v]){
                count(ans, adj, visited, v, restrictedSet);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> restrictedSet(restricted.begin(), restricted.end()); 
        vector<vector<int>> adj(n);
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(adj.size(),false);
        int ans=0;
        count(ans,adj, visited, 0, restrictedSet);
        return ans;
    }
};