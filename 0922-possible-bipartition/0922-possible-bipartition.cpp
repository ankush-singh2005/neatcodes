class Solution {
public:
    bool bipartite(unordered_map<int,vector<int>> &adj,vector<int> &color,int curr, int currColor){
        color[curr]=currColor;
        for(auto &v:adj[curr]){
            if(color[v]==color[curr]) return false;
            if(color[v]==-1){
                int colorOfV=1-color[curr];
                if(bipartite(adj,color,v,colorOfV)==false) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;
        for(auto &vec:dislikes){
            adj[vec[0]-1].push_back(vec[1]-1);
            adj[vec[1]-1].push_back(vec[0]-1);
        }
        // int n=adj.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bipartite(adj,color,i,1)==false) return false;
            }
        }
        return true;
    }
};