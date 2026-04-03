class Solution {
public:
    int dprobbery(int n, vector<int>& nums, vector<int> &dp){
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n]= max(dprobbery(n-1, nums, dp), nums[n] + dprobbery(n-2, nums, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dprobbery(nums.size()-1, nums, dp);
    }
};