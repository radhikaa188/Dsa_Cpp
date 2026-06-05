class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int count = 0;
        int n = mat.size();
        if (n%2 != 0) {//for odd
            for (int i = 0; i < n; i++) {
                if (i != (n) / 2) {
                    count += (mat[i][i] + mat[i][n - i - 1]);
                } else {
                    count += mat[i][i];
                }
            }
        } else { //for even
            for (int i = 0; i < n; i++) {
                count += (mat[i][i] + mat[i][n - i - 1]);
            }
        }
        return count;
    }
};