class Solution {
public:
    void fun(vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, int target, int ind){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i<nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;
            ds.push_back(nums[i]);
            fun(ans, ds, nums, target - nums[i], i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        fun(ans, ds, candidates, target, 0);
        return ans;
    }
};