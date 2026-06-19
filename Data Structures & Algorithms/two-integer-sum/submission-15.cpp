class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexNums;
        int n = nums.size();
        for(int i =0; i < n; i++){
            int diff = target - nums[i];
            if(indexNums.find(diff) != indexNums.end()){
                return {indexNums[diff], i};
            }
            indexNums.insert({nums[i], i});
        }
        return {};
    }
};