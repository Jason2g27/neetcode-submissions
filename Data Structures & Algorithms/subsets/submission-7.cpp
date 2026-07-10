class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        traverse(nums, 0, cur);
        return result;
    }

    void traverse(vector<int>& nums, int i, vector<int> cur){
        if (i == nums.size()) {
            result.push_back(cur);
            return;
        }
        int next = nums[i];
        cur.push_back(next);
        traverse(nums, i+1, cur);
        cur.pop_back();
        traverse(nums, i+1, cur);
    }
};
