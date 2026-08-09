class Solution {
public:
    vector<int> dp;
    int res;
    int maxSubArray(vector<int>& nums) {
        dp.resize(nums.size(), INT_MIN);
        res = nums[0];
        memo(nums, 0);
        return res;
    }

    int memo(vector<int>& nums, int i){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i] != INT_MIN){
            return dp[i];
        }
        int cur = max(nums[i], nums[i] + memo(nums, i+1));
        res = max(res, cur);
        return dp[i] = cur;
    }
};
