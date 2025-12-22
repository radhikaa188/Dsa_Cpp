class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(target<matrix[0][0] || target>matrix[m-1][n-1]) return false;
        for(int i = 0; i<m; i++){
            if(target == matrix[i][n-1]) return true;
            else if(target < matrix[i][n-1]){
                for(int j=0; j<n-1; j++){
                    if(matrix[i][j] == target) return true;
                }
            }
        }
        return false;
    }
};