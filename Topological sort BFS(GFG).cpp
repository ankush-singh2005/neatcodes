//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int N=adj.size();
        
        //step 1: finding the indegree of all vertices
        vector<int> indegree(N, 0);
        for(int u=0;u<N;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        
        //step 2: adding the vertices with indegree 0 into the queue;
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        
        //step 3: simple bfs 
        vector<int> result;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            result.push_back(u);
            for(int &v:adj[u]){
                indegree[v]--;
                
                if(indegree[v]==0) q.push(v);
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
