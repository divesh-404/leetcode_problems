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
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return fun(m-1,n-1,dp,obstacleGrid);


        if(obstacleGrid[0][0]==1) return 0;

        //tabulation
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(r==0 && c==0) continue;
                if(obstacleGrid[r][c]==1){
                    dp[r][c]=0;
                    continue;
                }
                int left=0;
                if(c>0) left=dp[r][c-1];
                int up=0;
                if(r>0) up=dp[r-1][c];

                dp[r][c]=left+up;
            }
        }

        return dp[m-1][n-1];

        // space optimization

        // vector<int> prev(n,0);
        // for(int r=0;r<m;r++){
        //     vector<int> temp(n);
        //     for(int c=0;c<n;c++){
        //         if(r==0 && c==0){
        //             temp[0]=1;
        //             continue;
        //         }
        //         if(obstacleGrid[r][c]==1){
        //             temp[c]=0;
        //             continue;
        //         }
        //         int left=0;
        //         if(c>0) left=temp[c-1];
        //         int up=temp[c];
        //         temp[c]= left+up;
        //     }
        //     prev=temp;
        // }

        // return prev[n-1];
    }
};