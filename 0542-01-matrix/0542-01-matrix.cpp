class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
                else vis[i][j]=0;
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
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&mat[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=ans[r][c]+1;
                }
            }
        }

        return ans;
    }
};