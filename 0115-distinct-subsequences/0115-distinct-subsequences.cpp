class Solution {
public:
    int fun(int i,int j,string& s,string& t,vector<vector<long long>>& dp){
        //base cases
        if(j==0) return 1;
        if(i==0)  return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==t[j-1]) return dp[i][j]=fun(i-1,j-1,s,t,dp)+fun(i-1,j,s,t,dp);
        return dp[i][j]=fun(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));

        // return fun(n,m,s,t,dp);


        // tabulation
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][m];
    }
};