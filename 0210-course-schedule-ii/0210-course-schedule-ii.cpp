class Solution {
public:
    // bool dfsCycle(vector<int>& vis,vector<int>& pathVis,int node,vector<vector<int>>& adjLs,vector<int>& ans){
    //     vis[node]=1;
    //     pathVis[node]=1;
    //     for(auto it: adjLs[node]){
    //         if(!vis[it]){
    //             if(dfsCycle(vis,pathVis,it,adjLs,ans)) return true;
    //         }
    //         else if(pathVis[it]) return true;
    //     }
    //     pathVis[node]=0;
    //     ans.push_back(node);
    //     return false;
    // }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLs(numCourses);
        for(auto it: prerequisites){
            adjLs[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        // vector<int> vis(numCourses,0);
        // vector<int> pathVis(numCourses,0);

        // for(int i=0;i<numCourses;i++){
        //     if(vis[i]) continue;
        //     if(dfsCycle(vis,pathVis,i,adjLs,ans)) return {};
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;

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
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adjLs[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(ans.size()==numCourses) return ans;
        return {};
    }
};