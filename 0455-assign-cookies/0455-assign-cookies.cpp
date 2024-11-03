class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        int cnt = 0;
        int l = 0; //pointer for greed array
        int r = 0; //iterate while there are cookies available or children left to consider
        while(l < m && r < n){
            if(g[r] <= s[l]) r++;
            l++;
        }
        return r;
    }
};