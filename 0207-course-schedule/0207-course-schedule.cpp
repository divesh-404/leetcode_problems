class Solution {
public:
    // detectimg a cycle
    // bool dfs(vector<int>& vis,vector<int>& pathVis,int node,vector<vector<int>>& adjLs){
    //     vis[node]=1;
    //     pathVis[node]=1;
    //     for(auto it: adjLs[node]){
    //         if(!vis[it]){
    //             if(dfs(vis,pathVis,it,adjLs)) return true;
    //         }
    //         else if(pathVis[it]) return true;
    //     }
    //     pathVis[node]=0;
    //     return false;
    // }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLs(numCourses);
        for(auto it: prerequisites){
            adjLs[it[1]].push_back(it[0]);
        }

        // vector<int> vis(numCourses,0);
        // vector<int> pathVis(numCourses,0);

        // for(int i=0;i<numCourses;i++){
        //     if(vis[i]) continue;
        //     if(dfs(vis,pathVis,i,adjLs)) return false;
        // }
        // return true;

        //by topo sort

        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it: adjLs[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adjLs[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        return (topo.size()==numCourses);
    }
};