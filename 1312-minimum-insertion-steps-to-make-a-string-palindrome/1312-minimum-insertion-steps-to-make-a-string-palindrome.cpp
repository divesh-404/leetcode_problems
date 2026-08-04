class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();

        //tabulation
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int l=n;l>=1;l--){
            dp[l][l]=1;
            for(int r=l+1;r<=n;r++){
                if (s[l - 1] == s[r - 1])
                    dp[l][r] = 2 + dp[l + 1][r - 1];
                else
                    dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            }
        }

        return n-dp[1][n];
    }
};