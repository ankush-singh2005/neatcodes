class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, vector<int> &indegree, int numCourses){
        vector<int> result;
        queue<int> q;
        int count=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                result.push_back(i);
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    result.push_back(v);
                    count++;
                } 
            }
        }
        if(count==numCourses){
            return result;
        }
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto &v:prerequisites){
            int a=v[0];
            int b=v[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSort(adj,indegree, numCourses);
    }
};