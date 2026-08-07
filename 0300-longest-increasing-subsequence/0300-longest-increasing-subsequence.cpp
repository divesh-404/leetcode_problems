class Solution {
public:
    int fun(int i,int pi,int n,vector<int>& nums,vector<vector<int>>& dp){
        //base case
        if(i==n) return 0;

        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        int notTake=0+fun(i+1,pi,n,nums,dp);
        int take=0;
        if(pi==-1 || nums[i]>nums[pi]) take=1+fun(i+1,i,n,nums,dp);

        return dp[i][pi+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        //ind,prev_ind,nums,dp
        return fun(0,-1,n,nums,dp);
    }
};