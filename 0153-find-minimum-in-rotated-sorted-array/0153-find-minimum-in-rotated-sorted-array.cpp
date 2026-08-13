class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mini=INT_MAX;
        while(l<=h){
            int m=l + (h-l)/2;

            //if low<high then low is the lowest element
            if(nums[l]<nums[h]){
                mini=min(mini,nums[l]);
                break;
            }

            //checking if left half is sorted
            if(nums[l]<=nums[m]){
                mini=min(mini,nums[l]);
                l=m+1;
            }

            //checking if right half is sorted
            if(nums[m]<=nums[h]){
                mini=min(mini,nums[m]);
                h=m-1;
            }
        }
        return mini;
    }
};