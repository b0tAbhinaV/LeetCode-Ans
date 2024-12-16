class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        // Min-heap to store {value, index} pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            auto curr = pq.top();
            pq.pop();
            int val = curr.first;
            int idx = curr.second;

            val = val*multiplier;
            pq.push({val, idx});
        }

        vector<int> result(n);
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int val = curr.first;
            int idx = curr.second;

            result[idx] = val;
        }

        return result;
    }
};