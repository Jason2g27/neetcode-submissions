class Solution {
public:
    vector<int> house;
int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        house.resize(n, -1);
        int opt1 = traverse(nums, 0, n - 2);

        house.assign(n, -1); 
        int opt2 = traverse(nums, 1, n - 1);

        return max(opt1, opt2);
    }
int traverse(vector<int>& nums, int i, int end){
        if(i > end){
            return 0;
        }
        if(house[i] != -1){
            return house[i];
        }
        
        int robCurrent = nums[i] + traverse(nums, i + 2, end);
        int skipCurrent = traverse(nums, i + 1, end);
        
        return house[i] = max(robCurrent, skipCurrent);
    }
};
