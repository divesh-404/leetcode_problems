class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> time(n+1,INT_MAX);
        time[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int node=pq.top().second;
            int t=pq.top().first;
            pq.pop();
            if(t>time[node]) continue;
            for(auto it: adj[node]){
                int timeTakes=it.second;
                int adjNode=it.first;
                if(timeTakes+t<time[adjNode]){
                    time[adjNode]=timeTakes+t;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }
       int ans=0;
       for(int i=1;i<=n;i++){
        if(time[i]==INT_MAX) return -1;
        ans=max(ans,time[i]);
       }
       return ans;
    }
};