class Solution {
public:
    double f(double x, int n){
        if(n==1) return x;
        if(n==0) return 1;
        double ans, half;
            if(n%2==0){
                half=f(x,n/2);
                ans= half*half;
            }else{
                half=f(x,n/2);
                ans= half*half*x;
            }
        
        return ans;
    }
    double myPow(double x, int n) {
        if(n>0) return f(x,n);
        else return f(1/x, n);
    }
};