class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        //when ever the sum becomes <0 we make sum again 0 coz we want maximum sum and ele<0 will only decrease the toatl sum
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0) sum=0;
        }

        return maxi;
    }
};