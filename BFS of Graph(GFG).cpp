//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void BFS(vector<int> &result, vector<bool> &visited, unordered_map<int, vector<int>> &adj, int u){
        queue<int> q;
        q.push(u);
        visited[u]=true;
        result.push_back(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                    result.push_back(v);
                }
            }
        }
        
    }
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &mp) {
        // Code here
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<mp.size();i++){
            for(auto v:mp[i]){
                adj[i].push_back(v);
            }
        }
        vector<int> result;
        vector<bool> visited(mp.size(), false);
        BFS(result, visited, adj, 0);
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
