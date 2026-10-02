class Solution {
public:
    vector<int> memo;
    int lengthOfLIS(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result = max(result, traverse(nums, i));
        }
        return result;
    }
    int traverse(vector<int>& nums, int i){
        if(memo[i] != -1){
            return memo[i];
        }
        int res = 0;
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] < nums[j]){
                res = max(res, traverse(nums, j));
            }
        }
        return memo[i] = res+1;
    }
};
