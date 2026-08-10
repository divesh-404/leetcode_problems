class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int lastInd=0;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int pi=0;pi<i;pi++){
                if(nums[i]%nums[pi]==0 && 1+dp[pi]>dp[i]){
                    dp[i]=1+dp[i];
                    hash[i]=pi;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastInd=i;
            }
        }

        vector<int> temp(maxi);
        temp[maxi-1]=nums[lastInd];
        int ind=maxi-2;
        while(lastInd!=hash[lastInd]){
            lastInd=hash[lastInd];
            temp[ind--]=nums[lastInd];
        }

        return temp;
    }
};