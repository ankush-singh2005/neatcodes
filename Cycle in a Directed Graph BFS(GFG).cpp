//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int N=adj.size();
        vector<int> indegree(N,0);
        
        for(int u=0;u<N;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int count=0;
        while(!q.empty()){
            int u=q.front();
            count++;
            q.pop();
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        
        if(count==N) return false;
        else return true;
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
