class Solution {
public:
    //memoization
    int fun(int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int up=fun(i-1,j,dp);
        int left=fun(i,j-1,dp);

        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return fun(m-1,n-1,dp);

        //tabulation
        // vector<vector<int>> dp(m,vector<int>(n,0));
        // dp[0][0]=1;

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0) continue;
        //         int right=0;
        //         if(j>0) right=dp[i][j-1];
        //         int down=0;
        //         if(i>0) down=dp[i-1][j];
        //         dp[i][j]=right+down;
        //     }
        // }

        // return dp[m-1][n-1];

        //space optimization
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[0]=1;
                    continue;
                }
                int right=0;
                if(j>0) right=curr[j-1];
                int down=0;
                if(i>0) down=prev[j];
                curr[j]=right+down;
            }
            prev=curr;
        }

        return prev[n-1];

    }
};