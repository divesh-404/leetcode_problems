class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> after(2*k+1,0),curr(2*k+1,0);

        for(int i=n-1;i>=0;i--){
            for(int t=2*k-1;t>=0;t--){
                if(t%2==0){ //buy
                    curr[t]=max((-prices[i]+after[t+1]),after[t]);
                }
                else{//sell
                    curr[t]=max((+prices[i]+after[t+1]),after[t]);
                }
            }
            after=curr;
        }

        return after[0];
    }
};