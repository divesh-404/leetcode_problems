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
class Solution {
public:
    bool isValid(int nr, int nc, int n){
        return nr>=0 && nr<n && nc>=0 && nc<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU ds(n*n);
        // making the dsu data structure of all ones making diff components with ones adjacent
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0) continue;
                int dirR[]={-1,0,1,0};
                int dirC[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int nr=r+dirR[i];
                    int nc=c+dirC[i];
                    if(isValid(nr,nc,n) && grid[nr][nc]==1){
                        int node=r*n +c;
                        int adjNode=nr*n+nc;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
        //step 2: checking all zeros to count max value
        int mx=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1) continue;
                int dirR[]={-1,0,1,0};
                int dirC[]={0,-1,0,1};
                set<int> components;
                for(int i=0;i<4;i++){
                    int nr=r+dirR[i];
                    int nc=c+dirC[i];
                    if(isValid(nr,nc,n) && grid[nr][nc]==1){
                        int adjNode=nr*n+nc;
                        components.insert(ds.findPar(adjNode));
                    }
                }
                int sizeTotal=1;
                for(auto it:components){
                    sizeTotal+=ds.size[it];
                }
                mx=max(mx,sizeTotal);
            }
        }

        if(mx==0) return n*n;
        return mx;

    }
};