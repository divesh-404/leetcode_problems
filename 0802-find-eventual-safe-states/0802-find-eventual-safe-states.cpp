class Solution {
public:
    bool dfs(int node,vector<int>& vis,vector<int>& pathVis,vector<int>& safeNode,vector<vector<int>>& graph){
        vis[node]=1;
        pathVis[node]=1;

        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,safeNode,graph)) return true;
            }
            else if(pathVis[it]) return true;
            else if(!safeNode[it]) return true;
        }

        pathVis[node]=0;
        safeNode[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        // // for(int i=0;i<graph.size();i++){
        // //     for(auto it:adj[i]){
        // //         indegree[it]++;
        // //     }
        // // }
        // // queue<int> q;
        // // for(int i=0;i<graph.size();i++){
        // //     if(indegree[i]==0) q.push(i);
        // // }
        // vector<int> ans;
        // // while(!q.empty()){
        // //     int node=q.front();
        // //     q.pop();
        // //     ans.push_back(node);
        // //     for(auto it : adj[node]){
        // //         indegree[it]--;
        // //         if(indegree[it]==0) q.push(it);
        // //     }
        // // }
        // // sort(ans.begin(),ans.end());
        // // return ans;
        

    // dfs approach
    int n=graph.size();
    vector<int> vis(n,0);
    vector<int> pathVis(n,0);
    vector<int> safeNode(n,0);

    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        dfs(i,vis,pathVis,safeNode,graph);
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(safeNode[i]) ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    return ans;

    }
};