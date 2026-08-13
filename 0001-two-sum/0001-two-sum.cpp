class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int find=target-nums[i];
            if(!mp.count(find)){
                mp[nums[i]]=i;
            }
            else return {i,mp[find]};
        }

        return {-1,-1};
    }
};