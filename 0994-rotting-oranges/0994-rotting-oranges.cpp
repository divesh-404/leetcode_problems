class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    vis[i][j]=0;
                    cnt++;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int count=0;
        int tm=0;
        int dirRow[]={-1,0,1,0};
        int dirCol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++){
                int nRow=r +dirRow[i];
                int nCol=c +dirCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol]!=2 && grid[nRow][nCol]==1){
                    q.push({{nRow,nCol},t+1});
                    vis[nRow][nCol]=2;
                    count++;
                }
            }
        }
        if(cnt!=count) return -1;
        return tm;
    }
};