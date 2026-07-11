class Solution {
    static bool comparator(const vector<int>& temp1, const vector<int>& temp2){
        return temp1[1]<temp2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);
        int n = intervals.size();
        int cnt = 0,lastEndTime = INT_MIN;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=lastEndTime){
                cnt += 1;
                lastEndTime = intervals[i][1];
            }
        }
        return n-cnt;
    }
};