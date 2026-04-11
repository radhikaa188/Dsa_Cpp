class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>front(n,-1);
        for(int i=0; i<n; i++){
            front[i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            vector<int>curr(n, -1);
            for(int j=i;j>=0; j--){
                int up=triangle[i][j]+front[j];
                int left=triangle[i][j]+front[j+1];
                curr[j]=min(up, left);
            }
            front=curr;
        }
        return front[0];
    }
};