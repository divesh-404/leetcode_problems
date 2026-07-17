class Solution {
public:
    int dirRow[4]={-1,0,1,0};
    int dirCol[4]={0,1,0,-1};
    void bfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=r+dirRow[i];
                int col=c+dirCol[i];
                if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]=='1'){
                    vis[row][col]=1;
                    q.push({row,col});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
       
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};