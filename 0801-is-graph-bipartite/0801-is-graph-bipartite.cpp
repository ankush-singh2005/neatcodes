class Solution {
public:
    bool bipartiteDFS(vector<int> &color, vector<vector<int>>& adj, int curr, int currColor){
        
        //step 1: curr node ko color assign karo
        color[curr]=currColor;

        //step2: curr se kaha kaha jaa sakte hai use find karo and then perform the operations
        for(auto &v:adj[curr]){

            //agar adjacent ka color aur current ka color same hai then false
            if(color[v]==color[curr]) return false;

            //agar adjacent visited ni hai then assign the color
            if(color[v]==-1){
                int colorOfV=1-color[curr];
                if(bipartiteDFS(color,adj,v,colorOfV)==false) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> color(n,-1);

        //red=1
        //green=0

        //checking whether the graph is bipartite or not
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bipartiteDFS(color,adj,i,1)==false) return false;
            }
        }
        return true;
    }
};