class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        map<char, int> map1;
        multimap<int, char, greater<int>> map2;
        for(auto x: s){
            map1[x]++;
        }
        for(auto it: map1){
            map2.insert({it.second, it.first});
        }
        string ans = "";
        for(auto it: map2){
            string temp = "";
            int a = it.first;
            while(a){
                temp += it.second;
                a--;
            }
            ans += temp;
        }
        return ans;
    }
};