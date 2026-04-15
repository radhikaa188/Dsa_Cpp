class Solution {
public:
    int sum(int idx, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(idx==0){
            if(target%nums[idx] == 0) return 1;
            else{
                return 0;
            }
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int not_take=sum(idx-1, target, nums, dp);
        int take=0;
        if(target>=nums[idx]) take=sum(idx, target-nums[idx], nums, dp);
        return dp[idx][target] = take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        return sum(coins.size()-1, amount, coins, dp);
    }
};