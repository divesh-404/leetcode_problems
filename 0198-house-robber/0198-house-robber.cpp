class Solution {
public:
    // memoization
    // int fun(int ind,vector<int>& dp,vector<int>& nums){
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int pick=nums[ind]+fun(ind-2,dp,nums);
    //     int notpick=fun(ind-1,dp,nums);
    //     return dp[ind]=max(pick,notpick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //memoization
        // vector<int> dp(n,-1);
        // return fun(n-1,dp,nums);
        
        //tabulation
        // vector<int> dp(n,0);
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int take=nums[i];
        //     if(i>1) take+=dp[i-2];
        //     int nottake=dp[i-1];
        //     dp[i]=max(take,nottake);
        // }

        // return dp[n-1];

        //space optimization;
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake=prev1;

            int curr=max(take,nottake);
            prev2=prev1;
            prev1=curr;
        }

        return prev1;

    }
};