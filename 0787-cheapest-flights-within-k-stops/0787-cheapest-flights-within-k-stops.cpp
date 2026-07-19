class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> prices(n,INT_MAX);
        prices[src]=0;

        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();

            if(stops>k) continue;

            for(auto it: adj[node]){
                int adjNode=it.first;
                int price=it.second;
                if(cost+price<prices[adjNode]){
                    prices[adjNode]=price+cost;
                    q.push({stops+1,{adjNode,prices[adjNode]}});
                }
            }

        }

        if(prices[dst]==INT_MAX) return -1;
        return prices[dst];
    }
};