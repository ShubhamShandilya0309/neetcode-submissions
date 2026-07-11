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
        return temp1.start < temp2.start;
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),compare);
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(intervals[0].end);
        for(int i=1;i<n;i++){
            if(pq.top()<=intervals[i].start){
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};
