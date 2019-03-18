/*Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      int n =  T.size();
      vector<int> res(n, 0);
      for (int i = n - 2; i >= 0; --i) {
        int count = 0;
        int j = i + 1;
        if (T[j] > T[i]) {
          res[i] = 1;
        } else if (T[j] == T[i]) {
          res[i] = res[j] == 0? 0: 1 + res[j];
        } else {
          if (res[j] == 0) {
            res[i] = 0;
            continue;
          }
          bool not_found = false;
          while (T[j] <= T[i]) {
            if (res[j] == 0 || j >= (n - 1)) {
              not_found = true;
              res[i] = 0;
              break;
            }
            if (T[j] == T[i]) {
              if (res[j] == 0) {
                res[i] = 0;
              } else {
                res[i] = res[j] + count + 1;
              }
              break;
            }
            
            count += res[j];
            j += res[j];
          }
          if (!not_found && T[j] > T[i]) {
            res[i] = count == 0? 0: count + 1;
          }
        }
      }
      return res;
    }
};