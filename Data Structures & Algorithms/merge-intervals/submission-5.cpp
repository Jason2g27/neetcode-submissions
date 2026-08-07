class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> results;
        results.push_back(intervals[0]);
        int index = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= results[index][1]){
                results[index][1] = max(intervals[i][1], results[index][1]);
            }
            else{
                results.push_back(intervals[i]);
                index++;
            }
        }
        return results;
    }
};
