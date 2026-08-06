class Solution {
public:
    int maxiProfit=0;
    int fun(int ind,int buy,int n,vector<int>& prices,vector<vector<int>>& dp){
        //base case
        if(ind==n-1){
            if(buy) return 0;
            else return prices[n-1];
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy) dp[ind][buy]=max((fun(ind+1,0,n,prices,dp)-prices[ind]),fun(ind+1,1,n,prices,dp));
        else dp[ind][buy]=max((fun(ind+1,1,n,prices,dp)+prices[ind]),fun(ind+1,0,n,prices,dp));

        return dp[ind][buy];
         
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return fun(0,1,n,prices,dp);
    }
};