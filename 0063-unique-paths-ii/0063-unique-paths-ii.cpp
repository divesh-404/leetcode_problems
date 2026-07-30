class Solution {
public:
    int fun(int r,int c, vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
        if(r<0 || c<0) return 0;
        if(obstacleGrid[r][c]==1) return dp[r][c]==0;
        if(dp[r][c]!=-1) return dp[r][c];
        if(r==0 and c==0) return dp[r][c]=1;

        int left =fun(r,c-1,dp,obstacleGrid);
        int up=fun(r-1,c,dp,obstacleGrid);

        return dp[r][c]=left+up;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp,obstacleGrid);
    }
};