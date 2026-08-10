class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),cnt(n,1);

        int maxi=1;
        for(int i=0;i<n;i++){
            for(int pi=0;pi<i;pi++){
                if(nums[i]>nums[pi]){
                    if(1+dp[pi]>dp[i]){
                        dp[i]=1+dp[pi];
                        cnt[i]=cnt[pi];
                    }
                    else if(1+dp[pi]==dp[i]){
                        cnt[i]+=cnt[pi];
                    }
                }
            }
            maxi=max(dp[i],maxi);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(maxi==dp[i]){
                ans+=cnt[i];
            }
        }

        return ans;
    }
};