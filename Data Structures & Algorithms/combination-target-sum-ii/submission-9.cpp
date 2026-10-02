class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        traverse(candidates, 0, target, cur);
        return results;
    }

    void traverse(vector<int>& candidates, int i, int target, vector<int>& cur){
        if(target == 0){
            results.push_back(cur);
            return;
        }
        if(i == candidates.size() || target < 0){
            return;
        }
        cur.push_back(candidates[i]);
        traverse(candidates, i+1, target-candidates[i], cur);
        cur.pop_back();
        while (i + 1 < candidates.size() && candidates[i + 1] == candidates[i]) i++;
        traverse(candidates, i+1, target, cur);
    }
};

