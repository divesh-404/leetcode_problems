class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        // top row
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                q.push({0,j});
                vis[0][j]=1;
            }
        }
        //left col
        for(int i=1;i<n-1;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }
        }
        //bottom row
        if(n>1){
            for(int j=0;j<m;j++){
                if(grid[n-1][j]==1){
                    q.push({n-1,j});
                    vis[n-1][j]=1;
                }
            }
        }
        //right col
        if(m>1){
            for(int i=1;i<n-1;i++){
                if(grid[i][m-1]==1){
                    q.push({i,m-1});
                    vis[i][m-1]=1;
                }
            }
        }

        int dirRow[]={-1,0,1,0};
        int dirCol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+dirRow[i];
                int ncol=c+dirCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                   vis[nrow][ncol]=1;
                   q.push({nrow,ncol});
                }
            }
        }
        int cnt=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};