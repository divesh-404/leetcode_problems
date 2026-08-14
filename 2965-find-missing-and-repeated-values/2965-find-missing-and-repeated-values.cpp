class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        //xor method
        int n=grid.size();
        int xr=0;
        int cnt=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                xr=xr^grid[i][j];
                xr=xr^cnt;
                cnt++;
            }
        }

        //we will get a xor in which where there will be bit one means at that index of bit the numbers differs

        int bitNo=0;
        while(1){
            if((xr&(1<<bitNo))!=0) break;
            bitNo++;
        }

        // now we got the bitNo at which both numbers bit differs
        // now we will divide every elements in zero and one group

        int zero=0;
        int one=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //part one club
                if((grid[i][j]&(1<<bitNo))!=0){
                    one=one^grid[i][j];
                }
                else{
                    zero=zero^grid[i][j];
                }
            }
        }

        //array with all correct elemenst
        for(int i=1;i<=n*n;i++){
            if((i&(1<<bitNo))!=0){
                one=one^i;
            }
            else{
                zero=zero^i;
            }
        }

        // now we got zero and one numbers 
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(zero==grid[i][j]) count++;
            }
        }

        if(count==2) return {zero,one};
        return {one,zero};

        

    }
};