class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=0) return 0;
        int l=0;
        int j=0;
        int count=0;
        int pd=1;
        while(j!=nums.size()){
            pd*=nums[j];
            while(pd >= k && l<=j){
                pd/=nums[l];
                l++;
            }
            count+=j-l+1;
            j++;

        }
        return count;
    }

};