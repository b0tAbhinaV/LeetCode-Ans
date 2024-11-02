class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        unordered_map<char, int> freq;
        int minLen = INT_MAX;
        int startIdx = -1;
        int left = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            freq[t[i]]++;
        }
        for(int right = 0; right < m; right++){
            if(freq[s[right]] > 0) cnt += 1;

            freq[s[right]]--;

            while(cnt == n){
                if(minLen > right-left+1){
                    minLen = right-left+1;
                    startIdx = left;
                }
                freq[s[left]]++; //Remove left character from window.
                if(freq[s[left]] > 0) cnt -= 1;
                left++;
            }
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};