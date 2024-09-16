class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long int n = x;
        long long int rev = 0;
        while(n > 0){
            int pop = n%10;
            n /= 10;
            // if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) {
            //     return 0;  // Overflow for positive numbers
            // }
            // if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) {
            //     return 0;  // Overflow for negative numbers
            // }
            rev = rev*10 + pop;
        }
        if(rev == x) return true;
        else return false;
    }
};