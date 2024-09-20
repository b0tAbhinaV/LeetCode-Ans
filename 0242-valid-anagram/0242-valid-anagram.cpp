class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int n = s.length();
        sort(s.begin(), s.end());
        // map<char, int> m = {"", 0};
        // for(int i=0; i<n; i++){
        //     m[i].first = s[i];
        //     m[i].second += 1;
        // }
        sort(t.begin(), t.end());
        for(int i=0; i<t.length(); i++){
            if(t[i] != s[i]) return false;
        }
        return true;
    }
};