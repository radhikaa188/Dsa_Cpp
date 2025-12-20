class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn= INT_MAX;
        int mx=INT_MIN;
        int maxIdx =0;
        int minIdx =0;
        int result=0;
        //Finding the min and max ele
        for(int i=0; i<nums.size(); i++){
            if(nums[i]> mx){
                mx=nums[i];
                maxIdx=i;
            }
            if(nums[i]<mn){
                mn=nums[i];
                minIdx=i;
            }
        }
         int left= min(minIdx, maxIdx);
         int right= max(minIdx, maxIdx);
         int n= nums.size();
         //returning the min of all three cases 
         // from left OR from right OR from both sides
        return min(right+1, min(n-left, (n-right) + (left+1)));
    }
};