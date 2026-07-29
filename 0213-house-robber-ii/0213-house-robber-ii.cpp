class Solution {
public:
    long long fun(vector<int>& nums){
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake=prev1;

            int cur=max(take,nottake);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }

        return max(fun(temp1),fun(temp2));
    }
};