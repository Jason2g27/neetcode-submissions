class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexNums;
        int n = nums.size();
        for(int i =0; i < n; i++){
            int diff = target - nums[i];
            auto it = indexNums.find(diff);
            if(it != indexNums.end()){
                return {it->second, i};
            }
            indexNums[nums[i]] = i;
        }
        return {};
    }
};