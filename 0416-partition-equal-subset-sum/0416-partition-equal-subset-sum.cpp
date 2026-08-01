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
        // vector<vector<int>> dp(n,vector<int>(subSum+1,-1));
        // return fun(n-1,subSum,nums,dp);

        // tabulation
        // vector<vector<bool>> dp(n,vector<bool>(subSum+1,0));
    
        // // if target becomes zero for any
        // for(int i=0;i<n;i++){
        //     dp[i][0]=1;
        // }
        // // at index 0 no matter what target is if it equals to arr[0]
        // if(nums[0]<=subSum) dp[0][nums[0]]=1;

        // for(int ind=1;ind<n;ind++){
        //     for(int tar=1;tar<=subSum;tar++){
        //         bool notTake=dp[ind-1][tar];
        //         bool take=false;
        //         if(tar>=nums[ind]) take=dp[ind-1][tar-nums[ind]];

        //         dp[ind][tar]=take | notTake;
        //     }
        // }

        // return dp[n-1][subSum];

        vector<bool> prev(subSum+1,0),curr(subSum+1,0);

        prev[0]=curr[0]=1;
        if(nums[0]<=subSum) prev[nums[0]]=1;

        for(int ind=1;ind<n;ind++){
            for(int tar=1;tar<=subSum;tar++){
                bool notTake=prev[tar];
                bool take=false;
                if(tar>=nums[ind]) take=prev[tar-nums[ind]];

                curr[tar]=take | notTake;
            }
            prev=curr;
        }

        return prev[subSum];
    }
};