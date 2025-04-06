class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result(n+1,INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &vec:times){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        result[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            for(auto &vec:adj[node]){
                int adjNode=vec.first;
                int d=vec.second;
                if(d+dist<result[adjNode]){
                    result[adjNode]=d+dist;
                    pq.push({d+dist, adjNode});
                }
            }
        }
        sort(result.begin() + 1, result.end()); 
        int maxTime=result[n];
        if(maxTime==INT_MAX) return -1;
        return maxTime;
        
    }
};