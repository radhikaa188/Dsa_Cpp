class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // calculate total sum
        int totalSum=0;
        for(int i=0; i<nums.size(); i++){
            totalSum+= nums[i];
        }

        int leftSum= 0;
        int rightSum=0;
        // keep the track of left and right sum
        for(int i=0; i<nums.size(); i++){
            // right sum is totalsum- leftsum- arr[i]
            rightSum= totalSum-nums[i]-leftSum;
            // if matched then return index 
            if(rightSum==leftSum) return i;
            leftSum+= nums[i];           
        }
        // if nothing matched return -1
        return -1;
    }
};