class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        traverse(nums, 0, cur);
        return results;
    }

    void traverse(vector<int>& nums, int i, vector<int>& cur){
        if(i == nums.size()){
            results.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        traverse(nums, i+1, cur);
        cur.pop_back();
        traverse(nums, i+1, cur);
    }
};

