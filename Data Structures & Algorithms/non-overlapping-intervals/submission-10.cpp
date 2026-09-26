class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {return a[0] < b[0];});
        int count = 0;
        int prev = INT_MIN;
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

