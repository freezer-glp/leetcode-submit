/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
      vector<Interval> res;
      if (intervals.size() <= 1) return intervals;
      sort(intervals.begin(), intervals.end(),
           [&](Interval& a, Interval& b)->bool 
           { if(a.start < b.start) { 
               return true;
             } else if (a.start == b.start) {
                return a.end < b.end;
             }
             return false;
           });
      
      res.push_back(intervals[0]);
      int idx = 1;
      while(idx < intervals.size()) {
        Interval& tmp = res[res.size() - 1];
        Interval& cur = intervals[idx];
        if (canMerge(tmp, cur)) {
          tmp.start = std::min(tmp.start, cur.start);
          tmp.end = std::max(tmp.end, cur.end);
        } else {
          res.push_back(std::move(intervals[idx]));
        }
        idx++;
      }
      
      return res;
    }
  
    bool canMerge(Interval& a, Interval& b) {
      if (b.start >= a.start && b.start <= a.end) {
        return true; 
      }
      return false;
    }
};