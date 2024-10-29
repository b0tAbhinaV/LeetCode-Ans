class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int left = 0;
        int n = s.length();
        unordered_map<char, int> mpp;
        for(int right=0; right<n; right++){
            if(mpp.count(s[right]) && mpp[s[right]] >= left){
                left = mpp[s[right]] + 1;
            }
            mpp[s[right]] = right;
            len = max(len, right-left+1);
        }
        return len;
    }
};