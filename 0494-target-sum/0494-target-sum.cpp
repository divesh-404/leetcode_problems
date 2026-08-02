class Solution {
public:
    int fun(int ind,int tar,vector<int>& nums,map<pair<int,int>,int>& mp){
        if(ind==0){
            if(tar==0 && nums[ind]==0) return 2;
            if(tar==nums[ind] || tar==-nums[ind]) return 1;
            return 0;
        }
        if(mp.count({ind,tar})) return mp[{ind,tar}];
        int pos=fun(ind-1,tar-nums[ind],nums,mp);
        int neg=fun(ind-1,tar+nums[ind],nums,mp);
        return mp[{ind,tar}]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        // map<pair<int,int>,int> mp;
        // return fun(n-1,target,nums,mp);

        // other method s1-s2 =target
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int subset=(sum-target)/2;
        if(sum-target<0) return 0;
        if((sum-target)%2!=0) return 0;

        vector<int> prev(subset+1,0) , curr(subset+1,0);

        if(nums[0]==0) prev[0]=2;
        else prev[0]=1;

        if(nums[0]!=0 && nums[0]<=subset) prev[nums[0]]=1;

        for(int i=1;i<n;i++){
            for(int tar=0;tar<=subset;tar++){
                int notTake=prev[tar];
                int take=0;
                if(nums[i]<=tar) take=prev[tar-nums[i]];
                curr[tar]=take+notTake;
            }
            prev=curr;
        }
        return prev[subset];

    }
};