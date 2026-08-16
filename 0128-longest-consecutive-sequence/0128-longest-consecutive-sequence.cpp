class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int maxi=0;
        for(auto &it:st){
            if(!st.count(it-1)){
                int start=it;
                int cnt=1;
                while(st.count(start+1)){
                    cnt++;
                    start++;
                }
                maxi=max(cnt,maxi);
            }
        }
        return maxi;
    }
};