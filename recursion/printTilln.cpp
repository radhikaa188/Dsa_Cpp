class Solution {
  public:
    void printTillN(int n) {
        //base case
        if(n==0) return;
        
        printTillN(n-1);
        cout << n << " ";
    }
};