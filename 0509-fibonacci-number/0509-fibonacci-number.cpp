class Solution {
public:
    int fun(int n,vector<int>& dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fun(n-1,dp)+fun(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
        
        // if(n<=1) return n;
        // dp[0]=0;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }

        // return dp[n];
    }
};