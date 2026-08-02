class Solution {
public:
    int fun(int ind,int tar,vector<int>& coins,vector<vector<int>>& dp){
        if(ind==0){
            if(tar%coins[ind]==0) return tar/coins[ind];
            else return 1e9;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];

        int notTake= 0+fun(ind-1,tar,coins,dp);
        int take=1e9;
        if(coins[ind]<=tar) take=1+fun(ind,tar-coins[ind],coins,dp);

        return dp[ind][tar]=min(take,notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        // if(fun(n-1,amount,coins,dp)==1e9) return -1;
        // return fun(n-1,amount,coins,dp);

        //tabulation 
        // vector<vector<int>> dp(n,vector<int>(amount+1,0));

        // for(int tar=0;tar<=amount;tar++){
        //     if(tar%coins[0]==0) dp[0][tar]=tar/coins[0];
        //     else dp[0][tar]=1e9;
        // }

        // for(int i=1;i<n;i++){
        //     for(int tar=0;tar<=amount;tar++){
        //         int notTake=0+dp[i-1][tar];
        //         int take=1e9;
        //         if(coins[i]<=tar) take=1+dp[i][tar-coins[i]];
        //         dp[i][tar]=min(take,notTake);
        //     }
        // }

        // return dp[n-1][amount]>=1e9?-1:dp[n-1][amount];

        //space optimization

        vector<int> prev(amount+1,0);
        for(int tar=0;tar<=amount;tar++){
            if(tar%coins[0]==0) prev[tar]=tar/coins[0];
            else prev[tar]=1e9;
        }

        for(int i=1;i<n;i++){
            vector<int> curr(amount+1,0);
            for(int tar=0;tar<=amount;tar++){
                int notTake=prev[tar];
                int take=1e9;
                if(coins[i]<=tar) take=1+curr[tar-coins[i]];

                curr[tar]=min(take,notTake);
            }
            prev=curr;
        }

        return prev[amount]>=1e9?-1:prev[amount];
    }
};