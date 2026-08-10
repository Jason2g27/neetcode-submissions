class Solution {
public:
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(), 2);
        memo(nums, 0);
        return dp[0];
    }

    bool memo(vector<int>& nums, int i){
        if(i >= nums.size()-1){
            return true;
        }
        if(dp[i] != 2){
            return dp[i];
        }
        for(int j = 1; j <= nums[i]; j++){
            if(memo(nums, i + j)){
                dp[i] = 1;
                return true;
            }
        }
        return dp[i] = 0;
    }
};
