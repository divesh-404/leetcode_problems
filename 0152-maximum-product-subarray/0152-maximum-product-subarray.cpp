class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //here even if product is -ve but is large and multipyling it a -ve el makes it large

        int n=nums.size();
        int maxi=nums[0];
        int maxEnding=nums[0];
        int minEnding=nums[0];

        for(int i=1;i<n;i++){
            int current=nums[i];
            int tempMax=max({current,maxEnding*current,minEnding*current});
            int tempMin=min({current,maxEnding*current,minEnding*current});
            
            maxEnding=tempMax;
            minEnding=tempMin;

            maxi=max(maxi,maxEnding);
        }

        return maxi;

    }
};