class Solution {
public:
    int atMost(vector<int> nums, int k){
        int n = nums.size();
        int left = 0;
        int cnt = 0;
        int odd = 0;
        for(int right = 0; right<n; right++){
            if(nums[right] % 2 != 0){
                odd += 1;
            }
            while(odd > k){
                if(nums[left] % 2 != 0) odd--;
                left++;
            }
            if(odd <= k){
                cnt += right-left+1;
            }
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};