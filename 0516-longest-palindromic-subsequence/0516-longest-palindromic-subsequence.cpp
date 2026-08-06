class Solution {
public:
    int fun(int l,int r,string& s,vector<vector<int>>& dp){
        if(l>r) return 0;
        if(l==r){
            if(s[l-1]==s[r-1]) return 1;
        }

        if(dp[l][r]!=-1) return dp[l][r];


        if(s[l-1]==s[r-1]) return dp[l][r]=2+fun(l+1,r-1,s,dp);

        return dp[l][r]=max(fun(l+1,r,s,dp),fun(l,r-1,s,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return fun(1,n,s,dp);
    }
};