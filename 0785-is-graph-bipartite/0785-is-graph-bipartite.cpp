class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        // -1=not visited/colored
        //0--> first color
        // 1--> second color
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]!=-1) continue;
            color[i]=0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:graph[node]){
                    // not visited/colored
                    if(color[it]==-1){
                        color[it]=1-color[node]; // if node color =1, then it color 0 and vice versa
                        q.push(it);
                    }
                    else if(color[it]==color[node]) return false;
                }
            }
        }
        return true;
    }
};