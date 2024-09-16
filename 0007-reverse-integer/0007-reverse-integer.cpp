class Solution {
public:
    int reverse(int x) {
        int rev = 0;  // This will store the reversed number
        while (x != 0) {
            int pop = x % 10;  // Extract the last digit
            x /= 10;           // Remove the last digit from x
            
            // Check if reversing would cause an overflow
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) {
                return 0;  // Overflow for positive numbers
            }
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) {
                return 0;  // Overflow for negative numbers
            }
            
            // Build the reversed number
            rev = rev * 10 + pop;
        }
        return rev;  // Return the reversed number
    }
};
