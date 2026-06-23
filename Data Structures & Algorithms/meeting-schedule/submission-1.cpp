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
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            if (a.start == a.end) {
                return a.end < b.end;
            }
            return a.start < b.start;
        });

        int prevEnd = -1;
        for (const Interval& interval : intervals) {
            if (interval.start < prevEnd) {
                return false;
            }
            prevEnd = interval.end;
        }
        return true;
    }
};
