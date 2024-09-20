class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(m != n) return false;

        for(int i=0; i<n; i++){
            s = s.substr(1) + s[0];
            if(s == goal) return true;
        }
        return false;
    }
};