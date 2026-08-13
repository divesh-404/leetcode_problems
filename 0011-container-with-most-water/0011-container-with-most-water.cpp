class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxi=INT_MIN;

        while(l<r){
            int water=min(height[l],height[r])*(r-l);
            maxi=max(maxi,water);
            height[l]<height[r]?l++:r--;
        }

        return maxi;
    }
};