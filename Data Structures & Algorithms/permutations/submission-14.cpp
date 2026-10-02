class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<bool> picked(nums.size(), false);
        traverse(nums, cur, picked);
        return result;
    }

    void traverse(vector<int>&nums, vector<int> cur, vector<bool> picked){
        if (cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }
        for (int j = 0; j < nums.size(); j++) {
            if (picked[j]) continue;
            cur.push_back(nums[j]);
            picked[j] = true;
            traverse(nums, cur, picked);
            cur.pop_back();
            picked[j] = false;
        }
    }
};