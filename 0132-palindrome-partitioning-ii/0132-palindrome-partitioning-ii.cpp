class Solution {
public:
    int fun(int i, string& s,vector<vector<int>>& isPal,vector<int>& dp){
        int n=s.size();
        if(i==n) return -1;
        if(dp[i]!=-1) return dp[i];

        int mini=1e9;
        for(int j=i;j<n;j++){
            if(isPal[i][j]){
                mini=min(mini,1+fun(j+1,s,isPal,dp));
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> isPal(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<2 || isPal[i+1][j-1])) isPal[i][j]=1;
            }
        }

        // vector<int> dp(n,-1);
        // return fun(0,s,isPal,dp);

        //tabulation

        vector<int> dp(n+1,0);
        dp[n]=-1;


        for(int i=n-1;i>=0;i--){
            int mini=1e9;
            for(int j=i;j<n;j++){
                if(isPal[i][j]) mini=min(mini,1+dp[j+1]);
            }
            dp[i]=mini;
        }

        return dp[0];
    }
};