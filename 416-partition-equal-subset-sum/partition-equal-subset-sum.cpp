class Solution {
public:
    bool halfSum(int n, int sum, vector<int>& nums, vector<vector<bool>>&dp){
        for(int i =0; i<n; i++){
            dp[i][0] = true;
        }
        if(nums[0]<=sum) dp[0][nums[0]] = true;
        for(int i =1; i<n; i++){
            for(int j=1; j<=sum; j++){
            bool notTake= dp[i-1][j];
            bool take=false;
            if(j>=nums[i]) take=dp[i-1][j-nums[i]];
            dp[i][j]=notTake || take;
            }
           
        }
         return dp[n-1][sum];
        }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i =0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2 !=0) return false;
        vector<vector<bool>>dp(nums.size(), vector<bool>(sum/2+1, 0));
        return halfSum(nums.size() ,sum/2 , nums, dp);
    }
};