class Solution {
public:
    int fun(int i,int pi,int n,vector<int>& nums,vector<vector<int>>& dp){
        //base case
        if(i==n) return 0;

        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        int notTake=0+fun(i+1,pi,n,nums,dp);
        int take=0;
        if(pi==-1 || nums[i]>nums[pi]) take=1+fun(i+1,i,n,nums,dp);

        return dp[i][pi+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // //ind,prev_ind,nums,dp
        // return fun(0,-1,n,nums,dp);

        //tabulation
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // for(int j=0;j<=n;j++){
        //     dp[n][j]=0;
        // }

        // for(int i=n-1;i>=0;i--){
        //     for(int j=i-1;j>=-1;j--){
        //         int notTake=0+dp[i+1][j+1];
        //         int take=0;
        //         if(j==-1 || nums[i]>nums[j]) take=1+dp[i+1][i+1];

        //         dp[i][j+1]=max(take,notTake);
        //     }
        // }

        // return dp[0][0];

        //space optimization

        // vector<int> after(n+1,0),curr(n+1,0);

        // for(int i=n-1;i>=0;i--){
        //     for(int j=i-1;j>=-1;j--){
        //         int notTake=0+after[j+1];
        //         int take=0;
        //         if(j==-1 || nums[i]>nums[j]) take=1+after[i+1];

        //         curr[j+1]=max(take,notTake);
        //     }
        //     after=curr;
        // }
        // return after[0];

        //some new method by dp[n]

        // vector<int> dp(n,1); //initially everyone assigned one
        // int maxLen=1;
        // for(int i=0;i<n;i++){
        //     for(int pi=0;pi<i;pi++){
        //         if(nums[i]>nums[pi]){
        //             dp[i]=max(dp[i],1+dp[pi]);
        //         }
        //         maxLen=max(maxLen,dp[i]);
        //     }
        // }

        // return maxLen;


        //using binary search and lower_bound

        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }

        return len;
    }
};