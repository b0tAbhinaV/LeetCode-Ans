class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();
        vector<int> count(26, 0);

        //store the frequencies of each character at their index as index of 'a'=0.
        for(char &ch : s){
            count[ch-'a']++;
        }

        int i = 25;
        string result;
        while(i >= 0){
            //traverse from back until find any freq > 0
            if(count[i] == 0){
                i--;
                continue;
            }

            //add to the result string until the freq which is calculated below
            //update the count[i] too after adding its freq char into result
            int freq = min(repeatLimit, count[i]);
            char c = 'a' + i;
            result.append(freq, c);
            count[i] -= freq;

            //
            if(count[i] > 0){
                int j = i-1;
                while(j >= 0 && count[j] == 0) j--;

                if(j < 0) break;
                result.push_back('a' + j);
                count[j]--;
            }
        }
        return result;
    }
};