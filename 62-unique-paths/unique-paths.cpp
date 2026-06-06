class Solution {
public:
    int count(int row, int col, int m, int n, vector<vector<int>>&dp){
        if(row>m-1 || col>n-1) return 0;
        if(row==m-1 && col==n-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col] = count(row, col+1, m, n, dp) + count(row+1, col, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return count(0, 0, m, n, dp);
    }
};