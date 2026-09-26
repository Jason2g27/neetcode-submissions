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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> inUse;
        for(auto& interval : intervals){
            inUse[interval.start]++;
            inUse[interval.end]--;
        }
        int current = 0;
        int res = 0;
        for(auto& [time, count] : inUse){
            current += count;
            res = max(res, current);
        }
        return res;
    }
};
