class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int> lis(n,1),cnt(n,1);
        int maxi=1;

        for(int i=0;i<n;i++){
            for(int pi=0;pi<i;pi++){
                if(nums[i]>nums[pi]){
                    if(1+lis[pi]>lis[i]){
                        lis[i]=1+lis[pi];
                        cnt[i]=cnt[pi];
                    }
                    else if(1+lis[pi]==lis[i]){
                        cnt[i]+=cnt[pi];
                    }
                }
            }
            maxi=max(maxi,lis[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(lis[i]==maxi){
                ans+=cnt[i];
            }
        }

        return ans;
    }
};