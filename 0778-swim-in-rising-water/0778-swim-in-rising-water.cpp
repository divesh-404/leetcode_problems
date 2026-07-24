class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=grid[0][0];

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});

        int dirR[]={-1,0,1,0};
        int dirC[]={0,-1,0,1};
        while(!pq.empty()){
            int time=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(time>dis[r][c]) continue;
            if(r==n-1 && c==n-1) return time;

            for(int i=0;i<4;i++){
                int nr=r+dirR[i];
                int nc=c+dirC[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int timeReq=grid[nr][nc];
                    int maxTime=max(time,timeReq);
                    if(maxTime<dis[nr][nc]){
                        dis[nr][nc]=maxTime;
                        pq.push({maxTime,{nr,nc}});
                    }
                }
            }

        }
        return 0;
    }
};