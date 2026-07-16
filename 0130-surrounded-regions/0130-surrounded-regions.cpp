class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        // top row
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                vis[0][j]=1;
            }
        }
        //left col
        for(int i=1;i<n-1;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
        }
        //bottom row
        if(n>1){
            for(int j=0;j<m;j++){
                if(board[n-1][j]=='O'){
                    q.push({n-1,j});
                    vis[n-1][j]=1;
                }
            }
        }
        //right col
        if(m>1){
            for(int i=1;i<n-1;i++){
                if(board[i][m-1]=='O'){
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
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                   vis[nrow][ncol]=1;
                   q.push({nrow,ncol});
                }
            }
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
    }
};