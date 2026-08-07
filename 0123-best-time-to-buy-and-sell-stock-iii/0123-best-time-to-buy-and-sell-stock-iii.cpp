class Solution {
public:
    int fun(int i,int n,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(cap==0) return 0;
        if(i==n) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            dp[i][buy][cap]=max((-prices[i]+fun(i+1,n,0,cap,prices,dp)),fun(i+1,n,1,cap,prices,dp));
        }
        else dp[i][buy][cap]=max((+prices[i]+fun(i+1,n,1,cap-1,prices,dp)),fun(i+1,n,0,cap,prices,dp));

        return dp[i][buy][cap];

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        //ind,n,buy,cap,prices,dp
        return fun(0,n,1,2,prices,dp);
    }
};