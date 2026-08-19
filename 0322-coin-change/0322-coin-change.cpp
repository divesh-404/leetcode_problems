class Solution {
public:
    int fun(int i,int target,vector<int>& coins,vector<vector<int>>& dp){
        //base cases
        if(i==0){
            if(target%coins[i]==0) return target/coins[i];
            else return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];

        int notTake=0+fun(i-1,target,coins,dp);
        int take=1e9;
        if(coins[i]<=target) take=1+fun(i,target-coins[i],coins,dp);

        return dp[i][target]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        if(fun(n-1,amount,coins,dp)==1e9) return -1;
        return fun(n-1,amount,coins,dp);
    }
};