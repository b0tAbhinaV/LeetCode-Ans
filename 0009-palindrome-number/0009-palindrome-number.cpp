class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long int n = x;
        long long int rev = 0;
        while(n > 0){
            int pop = n%10;
            n /= 10;
            rev = rev*10 + pop;
        }
        if(rev == x) return true;
        else return false;
    }
};