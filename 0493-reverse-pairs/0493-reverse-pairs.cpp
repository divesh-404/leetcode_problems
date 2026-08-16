class Solution {
public:
    int mergeSort(vector<int>& nums,int low,int high){
        if(low>=high) return 0;
        int mid=low+(high-low)/2;

        int count=0;
        count+=mergeSort(nums,low,mid);
        count+=mergeSort(nums,mid+1,high);

        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)nums[i]>2LL*nums[right]){
                right++;
            }
            count+=right-(mid+1);
        }

        int left=low;
        right=mid+1;

        vector<int> temp;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }

        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};