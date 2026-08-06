class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxiProfit=INT_MIN;

        for(int i=0;i<prices.size();i++){
            mini=min(prices[i],mini);
            maxiProfit=max(maxiProfit,(prices[i]-mini));
        }

        return maxiProfit;

    }
};