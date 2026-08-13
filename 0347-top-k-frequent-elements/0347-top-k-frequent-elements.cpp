class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // int n=nums.size();
        // unordered_map<int,int> freq;
        // for(int i=0;i<n;i++){
        //     freq[nums[i]]++;
        // }

        // vector<vector<int>> temp;
        // for(auto &x:freq){
        //     int element=x.first;
        //     int frequency=x.second;
        //     temp.push_back({frequency,element});
        // }

        // sort(temp.begin(),temp.end());

        // vector<int> ans;
        // int last=temp.size();
        // for(int i=last-1;i>=last-k;i--){
        //     ans.push_back(temp[i][1]);
        // }

        // return ans;

        //another method
        int n=nums.size();
        unordered_map<int,int> freq;
        for(auto &it:nums){
            freq[it]++;
        }

        vector<vector<int>> bucket(n+1);

        for(auto &it:freq){
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int i=n;i>=0;i--){
            for(auto &it:bucket[i]){
                ans.push_back(it);
                if(ans.size()==k) return ans;
            }
        }

        return ans;
    }
};