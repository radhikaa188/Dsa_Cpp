class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                pivot = i - 1;
                break;
            }
        }
        if (pivot < 0)
            return reverse(nums.begin(), nums.end());
        int nxtGr;
        int mn = INT_MAX;
        for (int i = pivot + 1; i < nums.size(); i++) {
            if (nums[i] > nums[pivot] && nums[i] <= mn) {
                mn = min(mn, nums[i]);
                nxtGr = i;
            }
        }
        int temp = nums[pivot];
        nums[pivot] = nums[nxtGr];
        nums[nxtGr] = temp;
        reverse(nums.begin() + pivot + 1, nums.end());
        return;
    }
};