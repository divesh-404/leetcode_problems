class Solution {
public:
    int change(int amount, vector<int>& coins) {

        //space optimization
        int n=coins.size();
        vector<unsigned long long> prev(amount+1,0);
        for(int tar=0;tar<=amount;tar++){
            if(tar%coins[0]==0) prev[tar]=1;
            else prev[tar]=0;
        }

        for(int i=1;i<n;i++){
            vector<unsigned long long> curr(amount+1,0);
            for(int tar=0;tar<=amount;tar++){
                unsigned long long notTake=prev[tar];
                unsigned long long take=0;
                if(coins[i]<=tar) take=curr[tar-coins[i]];

                curr[tar]=take+notTake;
            }
            prev=curr;
        }

        return prev[amount];
    }
};