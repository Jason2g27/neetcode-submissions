class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexNums;
        for(int i =0; i < nums.size(); i++){
            indexNums[nums[i]] = i; 
        }
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(indexNums.count(diff) && indexNums[diff] != i){
                return {i, indexNums[diff]};
            }
        }
        return {};
    }
};