class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;

        int dirRow[]={-1,-1,0,1,1,1,0,-1};
        int dirCol[]={0,1,1,1,0,-1,-1,-1};

        while(!pq.empty()){
            int weight=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;

            pq.pop();
            if(weight>dist[r][c]) continue;
            for(int i=0;i<8;i++){
                int row=r+dirRow[i];
                int col=c+dirCol[i];

                if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==0 && weight+1<dist[row][col]){
                    dist[row][col]=weight+1;

                    pq.push({dist[row][col],{row,col}});
                }
            }

        }

        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1]+1;


    }
};