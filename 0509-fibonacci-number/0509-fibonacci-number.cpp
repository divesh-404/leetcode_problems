class Solution {
public:
    // memoization
    // int fun(int n,vector<int>& dp){
    //     if(n<=1) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=fun(n-1,dp)+fun(n-2,dp);
    // }
    int fib(int n) {
        // vector<int> dp(n+1,-1);
        // return fun(n,dp);
        
        // tabulation with space
        // if(n<=1) return n;
        // dp[0]=0;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];

        // tabulation without extra space

        if(n<=1) return n;
        int prev2=0;
        int prev1=1;
        int curr;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }

        return curr;
    }
};