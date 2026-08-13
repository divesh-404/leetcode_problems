class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // right and left product
        int n=nums.size();
        vector<int> ans(n);
        //first stroring all the left products for every index(excluding that index)
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }

        //now for every index we will multiply its right produc and left prodct
        int rightProduct=1;
        for(int i=1;i<=n;i++){
            //ans=everyting right*everything left
            ans[n-i]=rightProduct*ans[n-i];
            rightProduct=rightProduct*nums[n-i];
        }

        return ans;
    }
};