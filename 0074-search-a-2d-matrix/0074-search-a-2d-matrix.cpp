class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();

        int l=0;
        int h=r*c-1;
        while(l<=h){
            int m=l+(h-l)/2;

            //2D to 1D conversion
            int row=m/c;
            int col=m%c;
            if(matrix[row][col]==target) return true;
            else if(target<matrix[row][col]) h=m-1;
            else l=m+1;

        }
        return false;
    }
};