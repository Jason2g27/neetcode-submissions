class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        sort(intervals.begin(), intervals.end());
        int i = 1;
        int index = 0;
        results.push_back(intervals[0]);
        while(i < intervals.size()){
            if(intervals[i][0] <= results[index][1]){
                results[index][1] = max(results[index][1], intervals[i][1]);
            }
            else{
                results.push_back(intervals[i]);
                index++;
            }
            i++;
        }
        return results;
    }
};



