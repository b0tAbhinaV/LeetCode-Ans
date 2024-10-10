class Solution {
public:
    long double power(double x, int n){
        if(n == 0) return 1;
        
        long double half = power(x, n/2);
        if(n % 2 == 0){
            return half*half; //n is even
        }
        else{
            return half*half*x; //n is odd
        }
    }
    double myPow(double x, int n) {
        if (n == INT_MIN) { 
            // Handle the edge case for INT_MIN
            return (1 / x) * power(1 / x, -(n + 1));
        }
        if(n < 0){
            return power(1/x, -n);
        }
        return power(x, n);
    }
};