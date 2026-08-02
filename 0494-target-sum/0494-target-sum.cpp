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
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        map<pair<int,int>,int> mp;
        return fun(n-1,target,nums,mp);
    }
};