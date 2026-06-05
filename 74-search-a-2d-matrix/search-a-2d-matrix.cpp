class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix[0].size() - 1;

        vector<int> column;

        for (int i = 0; i < matrix.size(); i++)
            column.push_back(matrix[i][n]);

        int row = binarySearch(column, target, 0, matrix.size() - 1);

        if (row == matrix.size())
            return false;

        int col = binarySearch(matrix[row], target, 0, matrix[0].size() - 1);

        if (col == matrix[0].size())
            return false;

        return matrix[row][col] == target;
    }
};