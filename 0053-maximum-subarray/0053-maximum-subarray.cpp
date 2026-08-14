class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //here we do the sum and when ever the sum becomes<0 we make it zero coxz we wnat max sum and -ve will just decrease
        int maxAns=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxAns=max(sum,maxAns);
            if(sum<0) sum=0;
        }

        return maxAns;
    }
};