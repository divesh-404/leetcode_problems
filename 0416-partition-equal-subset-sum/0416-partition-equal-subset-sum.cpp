class Solution {
public:
    bool fun(int ind,int subSum,vector<int>& nums,vector<vector<int>>& dp){
        if(subSum==0) return true;
        if(ind==0) return nums[ind]==subSum;

        if(dp[ind][subSum]!=-1) return dp[ind][subSum];

        bool notTake=fun(ind-1,subSum,nums,dp);
        bool take=false;
        if(nums[ind]<=subSum) take=fun(ind-1,subSum-nums[ind],nums,dp);

        return dp[ind][subSum]=take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        if(n==1) return false;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int subSum=sum/2;
        vector<vector<int>> dp(n,vector<int>(subSum+1,-1));
        return fun(n-1,subSum,nums,dp);
    }
};