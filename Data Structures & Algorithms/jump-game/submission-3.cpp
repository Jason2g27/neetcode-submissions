class Solution {
public:
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(), 2);
        memo(nums, 0);
        return dp[0];
    }

    int memo(vector<int>& nums, int i){
        if(i == nums.size()-1){
            return 1;
        }
        if(dp[i] != 2){
            return dp[i];
        }
        int sum = 0;
        for(int j = 1; j <= nums[i]; j++){
            if (i + j >= nums.size()) break;
            sum += memo(nums, i + j);
        }
        return dp[i] = sum == 0 ? 0 : 1;
    }
};
