class Solution {
public:
    int fun(int r1,int c1,int r2,int n,vector<vector<vector<int>>>& dp,vector<vector<int>>& grid){
        int c2=r1+c1-r2;
        //out of bounds
        if(r1>=n || c1>=n || r2>=n || c2>=n) return -1e8;
        //blocks
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1) return -1e8;
        //destination
        if(r1==n-1 && c1==n-1) return grid[r1][c1];

        //memoization
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
        int maxi=-1e8;
        //down, right
        int dr[]={1,0};
        int dc[]={0,1};
        for(int m1=0;m1<2;m1++){
            for(int m2=0;m2<2;m2++){
                int cherry=0;
                if(r1==r2 && c1==c2) cherry=grid[r1][c1];
                else cherry=grid[r1][c1] +grid[r2][c2];
                cherry+=fun(r1+dr[m1],c1+dc[m1],r2+dr[m2],n,dp,grid);
                maxi=max(maxi,cherry);
            }
        }

        return dp[r1][c1][r2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==-1 || grid[n-1][n-1]==-1) return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        //r1,c1,r2  c2=r1+c1-r2
        return max(0,fun(0,0,0,n,dp,grid));
    }
};