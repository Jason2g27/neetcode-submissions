class Solution {
public:
    unordered_map<string, int> dp;
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0);
    }

    int dfs(vector<int>& nums, int target, int i){
        if(i == nums.size()){
            return target == 0 ? 1 : 0;
        }
        string key = to_string(i) + "|" + to_string(target);
        if(dp.count(key) != 0){
            return dp[key];
        }
        return dp[key] = dfs(nums, target-nums[i], i+1) + dfs(nums, target+nums[i], i+1);
    }
};
