class Solution {
public:
    vector<int> house;
    int rob(vector<int>& nums) {
        house.resize(nums.size(), -1);
        return traverse(nums, 0);
    }
    int traverse(vector<int>& nums, int i){
        if(i >= nums.size()){
            return 0;
        }
        if(house[i] != -1){
            return house[i];
        }
        return house[i] = max(traverse(nums, i + 1), nums[i] + traverse(nums, i + 2));
    }
};
