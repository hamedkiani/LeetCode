class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        // if intervals has 0 or 1 entry just return intervals
        if (intervals.size() < 2)
            return intervals;

        // sort intervals based on the start values
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        int sz = intervals.size();

        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < sz; i++){

            if (intervals[i].start > res.back().end){
                res.push_back(intervals[i]);
            }
            else{
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};
