//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<int> &result, int u) {
        if (visited[u]) return;
        visited[u] = true;
        result.push_back(u);
        for (int &v : adj[u]) {
            if (!visited[v]) DFS(adj, visited, result, v);
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& mp) {
        unordered_map<int, vector<int>> adj;
        for (int u = 0; u < mp.size(); u++) {
            for (auto v : mp[u]) {
                adj[u].push_back(v);
            }
        }
        vector<int> result;
        vector<bool> visited(mp.size(), false);
        DFS(adj, visited, result, 0);
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

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
