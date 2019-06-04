/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
      vector<vector<int>> res;
      if (A.empty() || B.empty()) {
        return   res;      
      } 
      int i = 0, j = 0;
      while (i < A.size() && j < B.size()) {
        if (A[i][1] < B[j][0]) {
          i++;
        } else if (A[i][1] == B[j][0]) {
          vector<int> tmp;
          tmp.push_back(A[i][1]);
          tmp.push_back(A[i][1]);
          res.push_back(tmp);
          i++;
        } else if (A[i][1] > B[j][0] && A[i][1] <= B[j][1]) {
          if (A[i][0] <= B[j][0]) {
            vector<int> tmp;
            tmp.push_back(B[j][0]);
            tmp.push_back(A[i][1]);
            res.push_back(tmp);
            if (A[i][1] < B[j][1]) {
              i++;
            } else if (A[i][1] == B[j][1]) {
              i++;
              j++;
            }
          } else if (A[i][0] <= B[j][1]) {
            vector<int> tmp;
            tmp.push_back(A[i][0]);
            tmp.push_back(A[i][1]);
            res.push_back(tmp);
            i++;
          }
        } else if (A[i][1] > B[j][1]) {
          if (A[i][0] < B[j][0]) {
            vector<int> tmp;
            tmp.push_back(B[j][0]);
            tmp.push_back(B[j][1]);
            res.push_back(tmp);
          } else if (A[i][0] >= B[j][0] && A[i][0] <= B[j][1]) {
            vector<int> tmp;
            tmp.push_back(A[i][0]);
            tmp.push_back(B[j][1]);
            res.push_back(tmp);
          }
          j++;
        }
      }
      return res;
    }
};
// better way:
/*
class Solution {
    public Interval[] intervalIntersection(Interval[] A, Interval[] B) {
        List<Interval> ans = new ArrayList();
        int i = 0, j = 0;

        while (i < A.length && j < B.length) {
            // Let's check if A[i] intersects B[j].
            // lo - the startpoint of the intersection
            // hi - the endpoint of the intersection
            int lo = Math.max(A[i].start, B[j].start);
            int hi = Math.min(A[i].end, B[j].end);
            if (lo <= hi)
                ans.add(new Interval(lo, hi));

            // Remove the interval with the smallest endpoint
            if (A[i].end < B[j].end)
                i++;
            else
                j++;
        }

        return ans.toArray(new Interval[ans.size()]);
    }
}
*/