class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        int prev2=1;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int steps=prev1+prev2;
            prev2=prev1;
            prev1=steps;
        }

        return prev1;
    }
};