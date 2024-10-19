class Solution {
public:
    void fun(string &digits, int n, vector<string> &dict, vector<string> &ans, int idx, string temp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        string val = dict[digits[idx] - '0']; //characters for current digit
        for(int i = 0; i<val.size(); i++){
            temp += val[i]; //add current char to string
            fun(digits, n, dict, ans, idx+1, temp); //recur for next digit
            temp.pop_back(); //backtrack by removing last char
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.length();
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(n == 0) return ans;
        fun(digits, n, dict, ans, 0, "");
        return ans;
    }
};