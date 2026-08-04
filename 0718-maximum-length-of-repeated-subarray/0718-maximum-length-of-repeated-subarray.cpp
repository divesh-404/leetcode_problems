class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        //tabulation
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        // //base case
        // // if(nums1[0]==nums2[0]) dp[1][1]=1;
        // int len=0;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(nums1[i-1]==nums2[j-1]) dp[i][j]=1+dp[i-1][j-1];
        //         else dp[i][j]=0;
        //         len=max(len,dp[i][j]);
        //     }
        // }

        // return len;

        //space optimization

        vector<int> prev(m+1,0),curr(m+1,0); //coloums
        int len=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=0;
                len=max(len,curr[j]);
            }
            prev=curr;
        }

        return len;
    }
};