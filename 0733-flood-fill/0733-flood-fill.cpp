class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int intColor=image[sr][sc];
        if(intColor==color) return image;
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        // int vis[n][m];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(image[i][j]==color){
        //             q.push({i,j});
        //             vis[i][j]=color;
        //         }
        //         else{
        //             vis[i][j]=0;
        //         }
        //     }
        // }

        int dirRow[]={-1,0,1,0};
        int dirCol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+dirRow[i];
                int ncol=c+dirCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  && image[nrow][ncol]==intColor){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }

        return image;
    }
};