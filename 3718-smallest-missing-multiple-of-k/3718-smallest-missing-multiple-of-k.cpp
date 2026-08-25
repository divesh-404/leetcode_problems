class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int i=0;
        for(i;i<nums.size();i++){
            if(!mp.count(k*(i+1))) return k*(i+1);
        }

        return k*(i+1);
    }
};