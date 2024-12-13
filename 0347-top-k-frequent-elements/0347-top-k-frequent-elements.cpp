class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num]++;
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        for(auto it : mp){
            int freq = it.second;
            int val = it.first;
            pq.push({freq, val});

            if(pq.size() > k) pq.pop();
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};