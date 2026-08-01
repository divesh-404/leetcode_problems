class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;

        vector<int> left(nums.begin(), nums.begin()+n);
        vector<int> right(nums.begin()+n, nums.end());

        vector<vector<int>> L(n+1), R(n+1);

        // Generate all subset sums
        for(int mask=0; mask<(1<<n); mask++){

            int cnt=0;
            int sumL=0;
            int sumR=0;

            for(int i=0;i<n;i++){

                if(mask&(1<<i)){
                    cnt++;
                    sumL+=left[i];
                    sumR+=right[i];
                }
            }

            L[cnt].push_back(sumL);
            R[cnt].push_back(sumR);
        }

        for(int i=0;i<=n;i++)
            sort(R[i].begin(),R[i].end());

        int total=accumulate(nums.begin(),nums.end(),0);

        int ans=INT_MAX;

        for(int cntL=0;cntL<=n;cntL++){

            int cntR=n-cntL;

            for(int sumL:L[cntL]){

                double target=(double)total/2-sumL;

                auto &vec=R[cntR];

                auto it=lower_bound(vec.begin(),vec.end(),target);

                if(it!=vec.end()){

                    int subset=sumL+*it;
                    ans=min(ans,abs(total-2*subset));
                }

                if(it!=vec.begin()){

                    --it;

                    int subset=sumL+*it;
                    ans=min(ans,abs(total-2*subset));
                }
            }
        }

        return ans;
    }
};