class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();
        if(n<=1) return;
        //find pivot
        for(int i=n-2; i>=0; i--){
            if(nums[i+1]>nums[i]){
                pivot = i;
                break;
            }
        }
        //if last case
        if(pivot==-1 && n>1){
                reverse(nums.begin(), nums.end());
                return;
        }
        int i=n-1;
        while(i > pivot){
            if(nums[i]>nums[pivot]){
                swap(nums[i], nums[pivot]);
                reverse(nums.begin()+(pivot+1), nums.end());
                break;
            }else{
                i--;
            }
         }
         return;
    }
};