class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int maxi = 0;
        int count = 0;
        for(int it = 0; it<n; it++){
            if(s[it] == '('){
                count++;
                maxi = max(count, maxi);
            }
            else if(s[it] == ')') count--;
        }
        return maxi;
    }
};