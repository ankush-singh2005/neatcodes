class Solution {
public:
    bool topologicalSort(unordered_map<int, vector<int>> &adj, vector<int> &indegree, int numCourses){
        queue<int> q;
        int count=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    q.push(v);
                }
            }
        }
        if(count==numCourses) return true;
        return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses,0);

        //making the adj;
        for(auto &v:prerequisites){
            int a=v[0];
            int b=v[1];

            // b---->a
            adj[b].push_back(a);

            //kykui a me jaa rahe hai iskelie a ki indegree badhegi
            indegree[a]++;
        }

        return topologicalSort(adj, indegree, numCourses);


    }
};