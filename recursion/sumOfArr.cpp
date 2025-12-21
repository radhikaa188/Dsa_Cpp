// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int sum(vector<int> &arr, int idx){
        if(idx==-1) return 0;
        return arr[idx]+ sum(arr,idx-1);
    }
    int arraySum(vector<int>& arr) {
        return sum(arr, arr.size()-1);
    }
};