class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexNums;
        for(int i =0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(indexNums.find(diff) != indexNums.end()){
                return {indexNums[diff], i};
            }
            indexNums[nums[i]] = i; 
        }
        return {};
    }
};