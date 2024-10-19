class Solution {
public:
    void fun(vector<int> &nums, int n, vector<vector<int>> &ans, int idx, vector<int> &ds){
        ans.push_back(ds);

        for(int i=idx; i<n; i++){
            if(i != idx && nums[i-1] == nums[i]) continue;
            ds.push_back(nums[i]);
            fun(nums, n, ans, i+1, ds);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        fun(nums, n, ans, 0, ds);
        return ans;
    }
};