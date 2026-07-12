class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        traverse(nums, cur, 0);
        return results;
    }

    void traverse(vector<int>& nums, vector<int>& cur, int i){
        if(nums.size() == i){
            results.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        traverse(nums, cur, i+1);
        cur.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        traverse(nums, cur, i + 1);
    }
};
