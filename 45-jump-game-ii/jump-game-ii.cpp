class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int i =0;
        int reached=0;
        int steps=0;
        int currentEnd=0;
        while(i< nums.size()-1){
            reached = max(reached, nums[i]+i);
            if(i==currentEnd && i!=nums.size()-1) {
                steps++;
                currentEnd=reached;
            }
            i++;
        }
        return steps;
    }
};