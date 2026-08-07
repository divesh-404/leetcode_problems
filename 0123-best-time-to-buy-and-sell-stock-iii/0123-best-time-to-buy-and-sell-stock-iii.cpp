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
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // //ind,n,buy,cap,prices,dp
        // return fun(0,n,1,2,prices,dp);

        //tabulation
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        // for(int i=0;i<=n;i++){
        //     dp[i][0][0]=0;
        //     dp[i][1][0]=0;
        // }

        // for(int i=n-1;i>=0;i--){
        //     for(int c=2;c>=1;c--){
        //         dp[i][1][c]=max((-prices[i]+dp[i+1][0][c]),dp[i+1][1][c]);
        //         dp[i][0][c]=max((+prices[i]+dp[i+1][1][c-1]),dp[i+1][0][c]);
        //     }
        // }

        // return dp[0][1][2];

        //space optimization

        // vector<vector<int>> after(2,vector<int>(3,0));
        // vector<vector<int>> curr(2,vector<int>(3,0));

        // for(int i=n-1;i>=0;i--){
        //     for(int c=1;c<=2;c++){
        //         curr[1][c]=max((-prices[i]+after[0][c]),after[1][c]);

        //         curr[0][c]=max((+prices[i]+after[1][c-1]),after[0][c]);
        //     }
        //     after=curr;
        // }

        // return after[1][2];

        //N*4 solution
        //2 transactions-> B->S->B->S=4

        vector<int> after(5,0);
        vector<int> curr(5,0);

        for(int i=n-1;i>=0;i--){
            for(int t=3;t>=0;t--){
                if(t%2==0) curr[t]=max((-prices[i]+after[t+1]),after[t]);
                else curr[t]=max((+prices[i]+after[t+1]),after[t]);
            }
            after=curr;
        }

        return after[0];

        


    }
};