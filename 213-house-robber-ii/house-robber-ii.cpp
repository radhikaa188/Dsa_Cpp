class Solution {
public:
    int maxRobbery(vector<int>& nums, int startIdx, int lastIdx, vector<int>&dp) {
        int sum = 0;
        int n = lastIdx;
        if(n<startIdx) return 0;
        if (n == startIdx)
            return nums[n];
        if(dp[n]!= -1) return dp[n];
        return dp[n] = max(maxRobbery(nums, startIdx, n - 1, dp),
                  maxRobbery(nums, startIdx, n - 2, dp) + nums[n]);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp(nums.size(), -1);
        vector<int>dp2(nums.size(), -1);
        int ans_a = maxRobbery(nums, 0, nums.size() - 2, dp);
        int ans_b = maxRobbery(nums, 1, nums.size() - 1, dp2);
        return max(ans_a, ans_b);
    }
};