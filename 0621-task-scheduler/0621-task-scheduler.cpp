class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char ch : tasks){
            mp[ch]++;
        }
        int time = 0;
        priority_queue<int> pq;

        for(auto it: mp){
            pq.push(it.second);
        }

        while(!pq.empty()){
            vector<int> temp;
            for(int i=1; i<=n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    temp.push_back(freq-1);
                    //freq--;
                }
            }
            for(int &f : temp){
                if(f > 0){
                    pq.push(f);
                }
            }
            
            time += pq.empty() ? temp.size() : n + 1;
        }
        return time;
    }
};