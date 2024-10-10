class Solution {
public:
    long long int atoi(string s, int i, int sign, long long int result){
        if(sign*result >= INT_MAX) return INT_MAX;
        if(sign*result <= INT_MIN) return INT_MIN;
        if(i >= s.length() || s[i] < '0' || s[i] > '9'){
            return sign*result;
        }
        result = atoi(s, i+1, sign, (result*10 + (s[i] - '0')));
        return result;
    }
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        while(s[i] == ' ' && i < s.length()) i++;
        if(s[i] == '-') sign = -1, i++;
        else if(s[i] == '+') i++;

        return atoi(s, i, sign, 0);
    }
};