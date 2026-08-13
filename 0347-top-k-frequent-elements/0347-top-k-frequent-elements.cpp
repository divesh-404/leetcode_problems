class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> temp;
        for(auto &x:freq){
            int element=x.first;
            int frequency=x.second;
            temp.push_back({frequency,element});
        }

        sort(temp.begin(),temp.end());

        vector<int> ans;
        int last=temp.size();
        for(int i=last-1;i>=last-k;i--){
            ans.push_back(temp[i][1]);
        }

        return ans;
    }
};