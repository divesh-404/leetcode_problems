class Solution {
public:
    int fun(int r,int c,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(dp[r][c]!=-1) return dp[r][c];
        if(r==triangle.size()-1) return dp[r][c]=triangle[r][c];

        int num1=fun(r+1,c,triangle,dp);
        int num2=fun(r+1,c+1,triangle,dp);

        return dp[r][c]=triangle[r][c] +min(num1,num2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        
        // return fun(0,0,triangle,dp);

        //tabulation :- always reverse of memoization

        // vector<vector<int>> dp(n,vector<int>(n,0));
        // // base cases
        // for(int j=0;j<n;j++){
        //     dp[n-1][j]=triangle[n-1][j];
        // }
        
        // for(int r=n-2;r>=0;r--){
        //     for(int c=r;c>=0;c--){
        //         int num1=dp[r+1][c];
        //         int num2=dp[r+1][c+1];

        //         dp[r][c]=triangle[r][c]+min(num1,num2);
        //     }
        // }

        // return dp[0][0];

        // space optimization
        vector<int> next(n);
        for(int c=0;c<n;c++){
            next[c]=triangle[n-1][c];
        }

        for(int r=n-2;r>=0;r--){
            vector<int> temp(n,0);
            for(int c=r;c>=0;c--){
                int num1=next[c];
                int num2=next[c+1];

                temp[c]=triangle[r][c]+min(num1,num2);
            }
            next=temp;
        }

        return next[0];
    }
};