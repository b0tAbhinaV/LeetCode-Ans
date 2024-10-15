class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &subset, int start){
        //adding current subset to res. Starting from empty subset
        res.push_back(subset);

        for(int i=start; i<nums.size(); i++){
            //push the current element to form subset of this
            subset.push_back(nums[i]);
            //recurse with updated subset then move to next element
            backtrack(nums, res, subset, i+1);
            //backtrack: remove last element to explore other elements
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, res, subset, 0);
        return res;
    }
};