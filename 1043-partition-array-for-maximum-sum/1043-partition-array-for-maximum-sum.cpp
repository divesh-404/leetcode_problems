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
        // vector<int> dp(n,-1);
        // return fun(0,k,arr,dp);

        //tabulation

        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int maxi=-1e9;
            int maxiEl=-1e9;
            int len=0;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxiEl=max(maxiEl,arr[j]);
                int sum=len*maxiEl+dp[j+1];
                maxi=max(sum,maxi);
            }
            dp[i]=maxi;
        }

        return dp[0];
    }
};