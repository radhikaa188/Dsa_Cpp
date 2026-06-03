class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int f=m-1;
        int s=n-1;
        int p=nums1.size()-1;
        int c=n;
        while(c>0 && f>=0 && s>=0){
            if(nums1[f]>nums2[s]){
                nums1[p]=nums1[f];
                f--;
            }else if(nums1[f]<=nums2[s]){
                nums1[p]=nums2[s];
                s--;
            }
            p--;
            c--;
        }

        while(p>=0 && f>=0 && s>=0){
            if(nums1[f]>nums2[s]){
                nums1[p]=nums1[f];
                f--;
            }else if(nums1[f]<=nums2[s]){
                nums1[p]=nums2[s];
                s--;
            }
            p--;
        }
                if(f<0){
            while(s>=0){
                nums1[p] = nums2[s];
                p--; s--;
            }
        }
        if(s<0){
            while(f>=0){
                nums1[p] = nums1[f];
                p--; f--;
            }
        }
    }
};