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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU ds(n);
        unordered_map<string,int> mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(!mapMailNode.count(mail)){
                    mapMailNode[mail]=i;
                }
                else{
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }

        vector<string> mergeMail[n];
        for(auto it: mapMailNode){
            int node=ds.findPar(it.second);
            string mail=it.first;
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};