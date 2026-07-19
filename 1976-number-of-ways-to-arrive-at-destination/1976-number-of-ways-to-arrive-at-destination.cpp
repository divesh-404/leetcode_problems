class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> time(n,LLONG_MAX);
        time[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            int node=pq.top().second;
            long long t=pq.top().first;
            pq.pop();
            if(t>time[node]) continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                long long tem=it.second;
                if(tem+t<time[adjNode]){
                    time[adjNode]=tem+t;
                    ways[adjNode]=ways[node];
                    pq.push({time[adjNode],adjNode});
                }
                else if(tem+t==time[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
                }
            }

        }
        return ways[n-1];
    }
};