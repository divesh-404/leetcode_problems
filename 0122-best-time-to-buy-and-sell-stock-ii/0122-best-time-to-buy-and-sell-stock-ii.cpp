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
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return fun(0,1,n,prices,dp);

        //tabulation 
        // vector<vector<int>> dp(n+1,vector<int>(2,0));

        // dp[n-1][0]=prices[n-1];
        // dp[n-1][1]=0;

        // for(int i=n-1;i>=0;i--){
        //     for(int b=0;b<=1;b++){
        //         if(b) dp[i][b]=max((-prices[i]+dp[i+1][0]),dp[i+1][1]);
        //         else dp[i][b]=max((+prices[i]+dp[i+1][1]),dp[i+1][0]);
        //     }
        // }

        // return dp[0][1];

        //space optimization

        // vector<int> next(2,0);

        // next[0]=prices[n-1]; //selling on last day
        // next[1]=0; //buying on last day

        // for(int i=n-2;i>=0;i--){
        //     vector<int> curr(2,0);
        //     curr[0]=max((+prices[i]+next[1]),next[0]); // if we sell or not sell on this day
        //     curr[1]=max((-prices[i]+next[0]),next[1]); //if we are buying or not in this day
        //     next=curr;
        // }
        // return next[1];

        //also this

        int maxPro=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                maxPro+=prices[i]-prices[i-1];
            }
        }

        return maxPro;

    }
};