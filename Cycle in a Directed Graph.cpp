//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycleDFS(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion, int u){
        visited[u]=true;
        inRecursion[u]=true;
        for(auto &v:adj[u]){
            if(visited[v]==false && isCycleDFS(adj, visited, inRecursion, v)) return true;
            if(inRecursion[v]==true) return true;
        }
        inRecursion[u]=false;
        return false;
    }
    
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        vector<bool> visited(adj.size(), false);
        vector<bool> inRecursion(adj.size(), false);
        for(int i=0;i<adj.size();i++){
            if(!visited[i] && isCycleDFS(adj, visited, inRecursion, i)) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
