class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x, int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x==parent_y) return;
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
        
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        //step 1 : making components 
        for(auto &vec:edges){
            Union(vec[0],vec[1]);
        }

        //step 2 : making map to find the number of edges in each component
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int father=find(i);
            mp[father]++;
        }

        //step 3 : finding out the number of unreachable nodes using the formula
        // result = size * (remainingNodes-size)
        long long result=0;
        long long remainingNodes=n;
        for(auto it:mp){
            long long size=it.second;
            result += size * (remainingNodes-size);
            remainingNodes -= size;
        }
        return result;
    }
};