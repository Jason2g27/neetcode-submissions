/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto&x, auto& y) {
            return x.start < y.start;
        });
        int end = 0;
        for(auto& interval : intervals){
            if(end > interval.start){
                return false;
            }
            end = interval.end;
        }
        return true;
    }
};
