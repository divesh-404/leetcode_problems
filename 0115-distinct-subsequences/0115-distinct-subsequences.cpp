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
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));

        return fun(n,m,s,t,dp);
    }
};