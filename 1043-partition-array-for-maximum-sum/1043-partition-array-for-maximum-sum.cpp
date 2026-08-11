class Solution {
public:
    int fun(int ind,int k,vector<int>& arr,vector<int>& dp){
        int n=arr.size();
        //base case
        if(ind==n) return 0;

        if(dp[ind]!=-1) return dp[ind];
        int maxiEl=-1e9;
        int maxi=-1e9;
        int len=0;
        for(int j=ind;j<min(n,ind+k);j++){
            len++;
            maxiEl=max(maxiEl,arr[j]);
            int sum=len*maxiEl + fun(j+1,k,arr,dp);
            maxi=max(sum,maxi);
        }

        return dp[ind]=maxi;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);

        return fun(0,k,arr,dp);
    }
};