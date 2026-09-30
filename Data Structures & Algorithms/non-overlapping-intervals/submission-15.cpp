class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){return x[0] < y[0];});
        int prev = INT_MIN;
        int count = 0;
        for(auto& interval : intervals){
            if(interval[0] < prev){
                count++;
                prev = min(prev, interval[1]);
            }else{
                prev = interval[1];
            }
        }
        return count;
    }
};
