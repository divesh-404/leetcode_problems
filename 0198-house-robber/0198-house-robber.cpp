class Solution {
public:
    int fun(int ind,vector<int>& dp,vector<int>& nums){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+fun(ind-2,dp,nums);
        int notpick=fun(ind-1,dp,nums);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int ind=nums.size()-1;
        vector<int> dp(ind+1,-1);
        return fun(ind,dp,nums);
    }
};