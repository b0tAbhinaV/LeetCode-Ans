class Solution {
public:
    char nextChar(char c){
        if(c == 'z') return 'a';
        return c+1;
    }
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() < k){
            string addPart;
            for(char c: word){
                addPart += nextChar(c);
            }
            word += addPart;
        }
        return word[k-1];
    }
};