class Solution {
public:
    vector<vector<int>> store;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum+=i;
        }
        if(sum % 2 != 0){
            return false;
        }
        store.resize(nums.size(), vector<int>(sum/2+1, -1));
        return traverse(nums, 0, sum/2);
    }

    bool traverse(vector<int>& nums, int i, int target){
        if(i >= nums.size()){
            return target == 0;
        }
        if(target < 0){
            return false;
        }
        if(store[i][target] != -1){
            return store[i][target];
        }
        return store[i][target] = traverse(nums, i+1, target) || traverse(nums, i+1, target-nums[i]);
    }
};
