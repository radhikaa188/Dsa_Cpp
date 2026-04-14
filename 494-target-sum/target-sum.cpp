class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for(int x : nums) total += x;

        if((total + target) % 2 != 0) return 0;
        if(total < abs(target)) return 0;

        int tar = (total + target) / 2;

        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        // Base case (i = 0)
        if(nums[0] == 0) {
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
            if(nums[0] <= tar)
                dp[0][nums[0]] = 1;
        }

        // Fill table
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= tar; j++) {

                int not_take = dp[i-1][j];

                int take = 0;
                if(nums[i] <= j)
                    take = dp[i-1][j - nums[i]];

                dp[i][j] = take + not_take;
            }
        }

        return dp[n-1][tar];
    }
};