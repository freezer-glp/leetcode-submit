/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      int m[26] = {0};
      int maxn = 0;
      int max_idx = 0;
      for (int i = 0; i < tasks.size(); ++i) {
        int idx = tasks[i] - 'A';
        m[idx]++;
        if (m[idx] > maxn) {
          maxn = m[idx];
          max_idx = idx;
        }
      }
      int max_size = 0;
      for (auto& i : m) {
        if (i == maxn) {
          max_size++;
        }
      }
      
      return max((maxn - 1) * n + maxn + max_size - 1, (int)tasks.size());
    }
};