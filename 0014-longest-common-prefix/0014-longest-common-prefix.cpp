class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n = strs.size();
        string temp = strs[0];
        int strlen = temp.length();
        for(int i=1; i<n; i++){
            int cnt = 0;
            for(int j=0; j<strs[i].length(); j++){
                if(strs[i][j] == temp[j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            strlen = min(cnt, strlen);
        }
        return temp.substr(0, strlen);
    }
};