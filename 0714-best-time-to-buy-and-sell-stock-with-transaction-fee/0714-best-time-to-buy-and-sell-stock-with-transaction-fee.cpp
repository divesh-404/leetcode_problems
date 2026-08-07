class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //space optimization
        int n=prices.size();
        vector<int> after(2,0),curr(2,0);

        for(int i=n-1;i>=0;i--){
            curr[1]=max((-prices[i]+after[0]),after[1]);
            curr[0]=max((+prices[i]+after[1]-fee),after[0]);
            after=curr;
        }

        return after[1];

        
    }
};