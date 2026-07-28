class Solution {
public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        // if(n==2) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=nums[1];
        int maxrob=max(dp[0],dp[1]);
        for(int i=2;i<n;i++){
            int rob1=nums[i]+dp[i-2];
            int rob2=INT_MIN;
            if(i>=3) rob2=nums[i]+dp[i-3];
            dp[i]=max(rob1,rob2);
            maxrob=max(maxrob,dp[i]);
            
        }
        return maxrob;
    }
};