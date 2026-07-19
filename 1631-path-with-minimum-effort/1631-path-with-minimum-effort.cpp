class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        int dirRow[]={-1,0,1,0};
        int dirCol[]={0,1,0,-1};

        while(!pq.empty()){
            int effort=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(effort>dist[r][c]) continue;

            if(r==n-1 && c==m-1) return effort;

            for(int i=0;i<4;i++){
                int row=r+dirRow[i];
                int col=c+dirCol[i];

                if(row>=0 && row<n && col>=0 && col<m){
                    int edgeDiff=abs(heights[row][col]-heights[r][c]);
                    int newEffort=max(effort,edgeDiff);
                    if(newEffort<dist[row][col]){
                        dist[row][col]=newEffort;
                        pq.push({newEffort,{row,col}});
                    }
                }
            }
        }
        return 0;
    }
};