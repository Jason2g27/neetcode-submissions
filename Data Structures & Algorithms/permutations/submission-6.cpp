class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<int> picked(nums.size(), false);
        traverse(nums, cur, picked);
        return results;
    }

    void traverse(vector<int>& nums, vector<int>& cur, vector<int>& picked){
        if(cur.size() == nums.size()){
            results.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(picked[i]){
                continue;
            }
            cur.push_back(nums[i]);
            picked[i] = true;
            traverse(nums, cur, picked);
            cur.pop_back();
            picked[i] = false;
        }
    }
};
