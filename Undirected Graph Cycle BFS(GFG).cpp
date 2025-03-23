//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to detect cycle in an undirected graph using DFS.
    bool isCycleBFS(vector<vector<int>>& adj, vector<bool>& visited, int u) {
        queue<pair<int,int>> q;
        q.push({u, -1});
        visited[u]=true;
        while(!q.empty()){
            int source=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto &v:adj[source]){
                if(!visited[v]){
                    q.push({v,source});
                    visited[v]=true;
                }
                else if(v!=parent) return true;
            }
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(), false);
        for (int i = 0; i < adj.size(); i++) {
            if (!visited[i] && isCycleBFS(adj, visited, i)) return true;
        }
        return false;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
