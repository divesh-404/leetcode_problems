class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> codes(n,-1);

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            vis[i]=1;
            codes[i]=0;
            queue<pair<int,int>> q;
            q.push({i,0});
            while(!q.empty()){
                int node=q.front().first;
                int code=q.front().second;
                q.pop();
                for(auto it:graph[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        if(code){
                            q.push({it,0});
                            codes[it]=0;
                        }
                        else{
                            q.push({it,1});
                            codes[it]=1;
                        }
                    }
                    else if(code==codes[it]) return false;
                }
            }
        }
        return true;
    }
};