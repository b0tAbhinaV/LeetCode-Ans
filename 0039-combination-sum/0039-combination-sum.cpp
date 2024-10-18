class Solution {
public:
    void fun(vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, int target, int ind){
        if(ind == nums.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(nums[ind] <= target){
            ds.push_back(nums[ind]);
            fun(ans, ds, nums, target - nums[ind], ind);
            ds.pop_back();
        }

        fun(ans, ds, nums, target, ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        fun(ans, ds, candidates, target, 0);
        return ans;
    }
};