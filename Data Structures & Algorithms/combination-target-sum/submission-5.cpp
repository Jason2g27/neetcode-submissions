class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        traverse(nums, target, 0, cur);
        return result;
    }

    void traverse(vector<int> nums, int target, int i, vector<int> cur){
        int sum = 0;
        for(int j : cur){
            sum+=j;
        }
        if(sum > target){
            return;
        }
        if(sum == target){
            result.push_back(cur);
            return;
        }
        if(i == nums.size()){
            return;
        }
        int next = nums[i];
        cur.push_back(next);
        traverse(nums, target, i, cur);
        cur.pop_back();
        traverse(nums, target, i + 1, cur);
    }
};
