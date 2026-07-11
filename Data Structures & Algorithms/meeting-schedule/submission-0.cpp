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
    static bool compare(const Interval & temp1, const Interval & temp2){
        return temp1.end < temp2.end;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int n = intervals.size();
        int lastMeetingEndTime = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(lastMeetingEndTime <= intervals[i].start){
                cnt+=1;
                lastMeetingEndTime = intervals[i].end;
            }
        }
        return n == cnt;
    }
};
