class Solution {
  public:
  //function to find the power
    int power(int rev, int n){
        if(rev==0) return 1;
        return n*power(rev-1, n);
    }
    int reverseExponentiation(int n) {
        int original = n;
        int rev = 0;
        // find the reverse of number
        while (n > 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n = n / 10;
        }
        return power(rev, original);
    }
};