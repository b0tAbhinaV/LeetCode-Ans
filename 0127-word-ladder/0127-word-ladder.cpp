class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
    
        // If the endWord is not in the wordList, return 0
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        // BFS initialization
        queue<pair<string, int>> q;  // pair: (word, number of steps)
        q.push({beginWord, 1});
        
        // Visited set to keep track of words we have already processed
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        // Perform BFS
        while (!q.empty()) {
            auto [currentWord, steps] = q.front();
            q.pop();
            
            // Try changing each character in the current word
            for (int i = 0; i < currentWord.size(); i++) {
                char originalChar = currentWord[i];
                
                // Try all 26 possible characters for this position
                for (char c = 'a'; c <= 'z'; c++) {
                    currentWord[i] = c;
                    
                    // If the new word is the endWord, return the number of steps
                    if (currentWord == endWord) {
                        return steps + 1;
                    }
                    
                    // If the new word is in the wordSet and has not been visited yet, add it to the queue
                    if (wordSet.find(currentWord) != wordSet.end() && visited.find(currentWord) == visited.end()) {
                        visited.insert(currentWord);
                        q.push({currentWord, steps + 1});
                    }
                }
                
                // Restore the character back to its original form
                currentWord[i] = originalChar;
            }
        }
        
        // If no transformation sequence exists, return 0
        return 0;
    }
};