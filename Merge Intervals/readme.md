# LeetCode 56. Merge Intervals

### Link: https://leetcode.com/problems/merge-intervals/

### Difficulty: Medium

## Description

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]

Output: [[1,5]]

Explanation: Intervals [1,4] and [4,5] are considered overlapping.

## Code and Explanation

```cpp
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        // if intervals has 0 or 1 entry just return intervals
        int sz = intervals.size();
        if (sz < 2)
            return intervals;
        // sort intervals based on the start values
        // we sort the array of structs based on their start time
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});        
        // output- we can use stack as well and use the top of stack instead of back of vector
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < sz; i++){
          // the last element of the array shows the maximum range seen so far
          // if there is no overlap then add it to the list
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
```

### Time Complexity
O(N log N) for sorting the array (merge sort, for example)

### Space Complexity
O(1) if we use inplace sort and do not count the output space as space Complexity. If we use stack then space Complexity is O(N)

### Useful Links

[![](http://img.youtube.com/vi/Z52tWkco7BM/0.jpg)](http://www.youtube.com/watch?v=Z52tWkco7BM "")
