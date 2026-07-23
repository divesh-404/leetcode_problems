class Solution {
public:
class DSU{
public:
    vector<int> size,parent;
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
    // void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
    //     vis[node]=1;
    //     for(auto it:adj[node]){
    //         if(!vis[it]) dfs(it,vis,adj);
    //     }
    // }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // if(connections.size()<(n-1)) return -1;
        // vector<vector<int>> adj(n);
        // for(auto it: connections){
        //     adj[it[0]].push_back(it[1]);
        //     adj[it[1]].push_back(it[0]);
        // }
        // vector<int> vis(n,0);
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(vis[i]) continue;
        //     count++;
        //     dfs(i,vis,adj);
        // }

        // return count-1;

        // by disjoint set method

        DSU ds(n);
        int extraEdges=0;
        for(auto it: connections){
            if(ds.findPar(it[0])==ds.findPar(it[1])){
                extraEdges++;
            }
            else ds.unionBySize(it[0],it[1]);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i) components++;
        }

        int ans=components-1;
        if(extraEdges>=ans) return ans;
        else return -1;

    }
};