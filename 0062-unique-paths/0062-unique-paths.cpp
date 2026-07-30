class Solution {
public:
    // memoization
    int fun(int row,int col,vector<vector<int>>& dp){
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==0 && col==0) return dp[row][col]=1;

        int right=fun(row,col-1,dp);
        int up=fun(row-1,col,dp);

        return dp[row][col]=right + up;

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

        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp);
        
    }
};