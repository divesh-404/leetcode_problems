class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD=1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it :roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        //dist,source
        pq.push({0,0});

        while(!pq.empty()){
            int node=pq.top().second;
            long long weight=pq.top().first;
            pq.pop();

            if(weight>dist[node]) continue;

            for(auto it:adj[node]){
                int adjNode=it.first;
                long long distance=it.second;
                if(distance+weight<dist[adjNode]){
                    ways[adjNode]=ways[node];
                    dist[adjNode]=distance+weight;
                    pq.push({dist[adjNode],adjNode});
                }
                else if(distance+weight==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
                }
            }
        }

        return ways[n-1];
    }
};