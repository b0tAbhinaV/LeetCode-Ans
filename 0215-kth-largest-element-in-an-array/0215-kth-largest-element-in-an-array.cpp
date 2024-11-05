class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int f = k-1;
        int n = nums.size();
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        while(f){
            pq.pop();
            f--;
        }
        return pq.top();
    }
};