class Solution {
public:
    int fun(int r,int c, vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(r<0 || c<0) return INT_MAX;
        if(dp[r][c]!=-1) return dp[r][c];
        if(r==0 && c==0) return dp[0][0]=grid[0][0];

        int left=fun(r,c-1,dp,grid);
        int up=fun(r-1,c,dp,grid);

        if(left==INT_MAX){
            return dp[r][c]=grid[r][c]+up;
        }
        else if(up==INT_MAX){
            return dp[r][c]=grid[r][c]+left;
        }

        return dp[r][c]=min((grid[r][c]+up),(grid[r][c]+left));

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //memoization
        // return fun(m-1,n-1,dp,grid);

        //tabulation
        dp[0][0]=grid[0][0];
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(r==0 && c==0) continue;
                int left=INT_MAX;
                if(c>0) left=dp[r][c-1];
                int up=INT_MAX;
                if(r>0) up=dp[r-1][c];

                if(left==INT_MAX){
                    dp[r][c]=grid[r][c]+up;
                }
                else if(up==INT_MAX){
                    dp[r][c]=grid[r][c]+left;
                }
                else{
                    dp[r][c]=min((grid[r][c]+left),grid[r][c]+up);
                }
            }
        }
        return dp[m-1][n-1];
    }
};