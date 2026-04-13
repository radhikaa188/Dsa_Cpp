class Solution {
public:
    // int minCoins(int idx, int target, vector<int>& coins,
    //              vector<vector<int>>& dp) {
    //     if (idx == 0) {
    //         if (target % coins[idx] == 0)
    //             return target / coins[idx];
    //         else
    //             return 1e9;
    //     }
    //     if (dp[idx][target] != -1)
    //         return dp[idx][target];
    //     int not_take = minCoins(idx - 1, target, coins, dp);
    //     int take = INT_MAX;
    //     if (target > coins[idx])
    //         take = 1 + minCoins(idx, target - coins[idx], coins, dp);
    //     return dp[idx][target] = min(take, not_take);
    // }

    // int tabulation(){

    // }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        for(int i=0; i<=amount; i++){
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
               dp[0][i] = 1e9;
        }
        for(int i=1; i<coins.size(); i++){
            for(int j=0; j<=amount; j++){
                int not_take = dp[i - 1][j];
                int take = INT_MAX;
                if (j >= coins[i])
                    take = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(take, not_take);
            }
        }
        int ans = dp[coins.size()-1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};