class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // if target is equals (0,0) or (m-1,n-1)
        if(target<matrix[0][0] || target>matrix[m-1][n-1]) return false;
        // check last index of each row
        for(int i = 0; i<m; i++){
            // if equal
            if(target == matrix[i][n-1]) return true;
            // if small then traverse in that row
            else if(target < matrix[i][n-1]){
                for(int j=0; j<n-1; j++){
                    if(matrix[i][j] == target) return true;
                }
            }
        }
        return false;
    }
};