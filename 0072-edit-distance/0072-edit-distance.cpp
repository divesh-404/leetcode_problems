class Solution {
public:
    int fun(int i,int j,string& word1,string& word2,vector<vector<int>>& dp){
        //base cases
        if(i==0) return j;
        if(j==0) return i;

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i-1]==word2[j-1]) return dp[i][j]=fun(i-1,j-1,word1,word2,dp);

        return dp[i][j]=1+min({fun(i-1,j,word1,word2,dp),fun(i,j-1,word1,word2,dp),fun(i-1,j-1,word1,word2,dp)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        // return fun(n,m,word1,word2,dp);

        //tabulation

        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        // for(int j=0;j<=m;j++){
        //     dp[0][j]=j;
        // }

        // for(int i=0;i<=n;i++){
        //     dp[i][0]=i;
        // }

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
        //         else dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
        //     }
        // }

        // return dp[n][m];

        //space optimization

        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=m;i++) prev[i]=i;

        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
                else curr[j]=1+min({prev[j],curr[j-1],prev[j-1]});
            }
            prev=curr;
        }

        return prev[m];
    }
};