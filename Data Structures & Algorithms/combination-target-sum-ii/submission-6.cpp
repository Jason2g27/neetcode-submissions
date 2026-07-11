class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        traverse(candidates, target, 0, cur);
        return results;
    }
    void traverse(vector<int>& candidates, int target, int j, vector<int>& cur){
        if(target == 0){
            results.push_back(cur);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = j; i < candidates.size(); i++){
            if(i > j && candidates[i] == candidates[i-1]){
                continue;
            }
            
            cur.push_back(candidates[i]);

            traverse(candidates, target - candidates[i], i + 1, cur);
            cur.pop_back();
        }
    }
};
