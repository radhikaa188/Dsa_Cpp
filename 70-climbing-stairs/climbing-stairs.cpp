class Solution {
public:
    int stairs(int n, vector<int> &dp){
        if(n==1 || n==0) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = stairs(n-1, dp)+stairs(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return stairs(n, dp);
    }
};