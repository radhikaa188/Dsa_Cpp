class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int temp=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0 && temp<nums.size()){
                nums[temp]=nums[i];
                temp++;
            }
        }
        int index=temp;
        while(index<nums.size()){
            nums[index]=0;
            index++;
        }
        return;
    }
};