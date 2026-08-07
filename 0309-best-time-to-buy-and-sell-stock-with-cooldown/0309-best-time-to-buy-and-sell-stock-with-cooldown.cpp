class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+2,vector<int>(2,0));

        // for(int i=n-1;i>=0;i--){
        //     dp[i][1]=max((-prices[i]+dp[i+1][0]),dp[i+1][1]); //buy or not nuy
        //     dp[i][0]=max((+prices[i]+dp[i+2][1]),dp[i+1][0]); //if sell then 1 day after buy 
        // }

        // return dp[0][1];

        //space optimization

        vector<int> after2(2,0),after1(2,0),curr(2,0);

        for(int i=n-1;i>=0;i--){
            curr[1]=max((-prices[i]+after1[0]),after1[1]);
            curr[0]=max((+prices[i]+after2[1]),after1[0]);
            after2=after1;
            after1=curr;
        }

        return after1[1];
    }
};