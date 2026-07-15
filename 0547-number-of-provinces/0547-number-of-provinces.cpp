class Solution {
public:
    // void dfs(vector<vector<int>>& adjLs,int node,vector<int>& vis){
    //     vis[node]=1;
    //     for(auto it: adjLs[node]){
    //         if(!vis[it]) dfs(adjLs,it,vis);
    //     }
    // }

    void dfs(vector<vector<int>>& isConnected,int node,vector<int>& vis){
        vis[node]=1;
        int n=isConnected.size();
        for(int j=0;j<n;j++){
            if(isConnected[node][j]==1 && !vis[j]){
                dfs(isConnected,j,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // int n=isConnected[0].size();
        // vector<vector<int>> adjLs(n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1 && i!=j){
        //             adjLs[i].push_back(j);
        //             adjLs[j].push_back(i);
                    
        //         }
        //     }
        // }

        // vector<int> vis(n,0);
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         cnt++;
        //         dfs(adjLs,i,vis);
        //     }
        // }
        // return cnt;

        //direct from matrix apporach

        int n=isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(isConnected,i,vis);
            }
        }
        return cnt;

    }
};