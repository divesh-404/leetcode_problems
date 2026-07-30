class Solution {
public:
    // memoization
    int fun(int row,int col,vector<vector<int>>& dp){
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==0 && col==0) return dp[row][col]=1;

        int left=fun(row,col-1,dp);
        int up=fun(row-1,col,dp);

        return dp[row][col]=left + up;

    }
    int uniquePaths(int m, int n) {
        // permutation method nCr
        // long long ans=1;
        // int N=(m-1)+(n-1);
        // int R=min((m-1),(n-1));
        // for(int i=1;i<=R;i++){
        //     ans=ans*(N-R+i)/i;
        // }
        // return (int)ans;

        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return fun(m-1,n-1,dp);

        //tabulation
        // vector<vector<int>> dp(m,vector<int>(n,0)); 
        // dp[0][0]=1;

        // for(int row=0;row<m;row++){
        //     for(int col=0;col<n;col++){
        //         if(row==0 && col==0) continue;
        //         int left=0;
        //         if(col>0) left=dp[row][col-1];
        //         int up=0;
        //         if(row>0) up=dp[row-1][col];

        //         dp[row][col]=left+up;
        //     }
        // }

        // return dp[m-1][n-1];

        // space optimization of tabulation

        vector<int> prev(n,0);

        for(int row=0;row<m;row++){
            vector<int> temp(n);
            for(int col=0;col<n;col++){
                if(row==0 && col==0){
                    temp[0]=1;
                    continue;
                }
                int left=0;
                if(col>0) left=temp[col-1];
                int up=prev[col];
                temp[col]=up+left;
            }
            prev=temp;
        }

        return prev[n-1];

        
    }
};