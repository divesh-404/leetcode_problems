class Solution {
public:
    int check(vector<int>& nums,int mid,int threshold){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0) sum+=nums[i]/mid;
            else sum+=nums[i]/mid +1;
        }
        if(sum<=threshold) return 1;
        return -1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        long long h= *max_element(nums.begin(),nums.end());
        int divisor=1;
        while(l<=h){
            int mid=l +(h-l)/2;
            int div=check(nums,mid,threshold);
            if(div==1){
                divisor=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return divisor;
    }
};