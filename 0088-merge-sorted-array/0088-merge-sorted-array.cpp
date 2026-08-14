class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n-1; //last valid position of nums1 where ele can go
        int l=m-1; //ele to compare in nums1
        int r=n-1; // ele to compare in nums2

        while(l>=0 && r>=0){
            if(nums1[l]>nums2[r]){
                nums1[k]=nums1[l];
                l--;
            }
            else{
                nums1[k]=nums2[r];
                r--;
            }
            k--;
        }
        //if nums2 has still elemenst
        while(r>=0){
            nums1[k]=nums2[r];
            r--;
            k--;
        }
    }
};