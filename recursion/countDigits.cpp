class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int helperFun(int n, int org){
        int count =0;
        if(n<=0) return 0;
        int rem = n%10;
        if(org%rem == 0){
            count++;
        }
        return count+helperFun( n/10 , org);
        
    }
    int evenlyDivides(int n) {
        return helperFun(n,n);
    }
};