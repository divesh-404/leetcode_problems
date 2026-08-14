class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // by checking freq of each element
        // int n=grid.size();
        // vector<int> freq(n*n+1,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         freq[grid[i][j]]++;
        //     }
        // }

        // int missing =-1;
        // int repeating=-1;

        // for(int i=1;i<=n*n;i++){
        //     if(freq[i]==2){
        //         repeating=i;
        //     }
        //     if(freq[i]==0) missing=i;
        // }

        // return {repeating,missing};

        //mathematical method
        int m=grid.size();
        long long n=grid.size()*grid.size();
        //sum of all numbers=S
        long long S=(n*(n+1))/2;
        //sum of squares of all numbers->S^2
        long long S2=(n*(n+1)*(2*n+1))/6;

        long long s=0;
        long long s2=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                s+=grid[i][j];
                s2+=(long long)grid[i][j]*(long long)grid[i][j];
            }
        }
        //x-> repeating ele, y-> missing ele
        //S-s=x-y
        //S2-s2=(x-y)(x+y)->x^2-y^2

        long long val1=s-S;
        long long val2=s2-S2;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=x-val1;

        return {(int)x,(int)y};

    }
};