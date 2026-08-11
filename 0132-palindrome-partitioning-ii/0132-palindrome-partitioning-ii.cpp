class Solution {
public:
    int fun(int i,string& s,vector<int>& dp,vector<vector<int>>& isPal){
        int n=s.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];

        int mini=1e9;
        for(int j=i;j<n;j++){
            if(isPal[i][j]) mini=min(mini,1+fun(j+1,s,dp,isPal));
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

        vector<int> dp(n,-1);
        return fun(0,s,dp,isPal)-1;
    }
};